#include<iostream>
#include <set>
using namespace std;

long* getSequence(multiset<long>*& addToLeftBorder, multiset<long>*& addToRightBorder, const int n)
{
	multiset<long> temp;
	temp.insert(-1);
	long* answer = new long[n];
	for (int i = 0; i < n; i++)
	{
		for (multiset<long>::iterator it = addToLeftBorder[i].begin(); it != addToLeftBorder[i].end(); it++)
			temp.insert(*it);
		for (multiset<long>::iterator it = addToRightBorder[i].begin(); it != addToRightBorder[i].end(); it++)
			temp.erase(temp.find(*it));
		answer[i] = *temp.rbegin();
	}

	return answer;
}
void inputData(multiset<long>*& addToLeftBorder, multiset<long>*& addToRightBorder, const int n, const int m)
{
	long l, r, v;
	for (int i = 0; i < m; i++)
	{
		cin >> l;
		cin >> r;
		cin >> v;
		addToLeftBorder[l - 1].insert(v);
		if (r < n)
			addToRightBorder[r].insert(v);
	}
}
int main()
{

	multiset<long>* addToLeftBorder, * addToRightBorder;
	int n, m;
	cin >> n >> m;
	addToLeftBorder = new multiset<long>[n];
	addToRightBorder = new multiset<long>[n];
	inputData(addToLeftBorder, addToRightBorder, n, m);
	long* answer = getSequence(addToLeftBorder, addToRightBorder, n);
	for (int i = 0; i < n; i++)
	{
		cout << answer[i];
		cout << " ";
	}
	return 0;
}