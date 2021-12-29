#include <iostream>
#include <vector>
using namespace std;

void visitToVertex(int i, bool* isChecked, vector<vector<int>>& gr)
{
	isChecked[i] = true;
	vector<int>::iterator it = gr[i].begin();
	while (it != gr[i].end())
	{
		if (!isChecked[*it])
			visitToVertex(*it, isChecked, gr);
		++it;
	}

}
int tryToDelete(int k, int numberOfVertices, int numberOfRibs)
{
	if ((numberOfRibs - numberOfVertices + 1) >= 0 && k == 0)
		return numberOfRibs - numberOfVertices + 1;
	else
		return -1;
}
int main()
{
	int numberOfVertices, numberOfRibs, result = 0;
	int vertex1, vertex2;
	cin >> numberOfVertices;
	bool* isChecked = new bool[numberOfVertices];
	for (int i = 0; i < numberOfVertices; i++)
		isChecked[i] = false;
	cin >> numberOfRibs;
	vector<vector<int>> gr(numberOfVertices);
	for (int i = 0; i < numberOfRibs; i++)
	{
		cin >> vertex1;
		cin >> vertex2;
		vertex1--;
		vertex2--;
		gr[vertex1].push_back(vertex2);
		gr[vertex2].push_back(vertex1);
	}

	for (int i = 0; i < numberOfVertices; i++)
	{
		if (!isChecked[i])
		{
			visitToVertex(i, isChecked, gr);
			result++;
		}
	}
	result--;
	int answer = tryToDelete(result, numberOfVertices, numberOfRibs);
	cout << answer;


}