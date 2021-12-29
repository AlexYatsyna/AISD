#include <iostream>
#include <vector>
using namespace std;
long long modul = 1e7 + 7;
void checkSubTrS(vector<vector<pair< long long, long long >>>& tree, long long vertex, long long*& subTree)
{
	if (tree[vertex].size() == 1)
		subTree[vertex] = 1;
}
void dfs(vector<vector<pair< long long, long long >>>& tree, long long vertex, int n, long long& answer, long long*& subTree, long long*& distance, vector<bool>& isVisited)
{
	isVisited[vertex] = true;
	checkSubTrS(tree, vertex, subTree);
	for (vector<pair< long long, long long >> ::iterator it = tree[vertex].begin(); it != tree[vertex].end(); ++it)
	{
		if (!isVisited[(*it).first])
		{
			distance[(*it).first] = (*it).second;
			dfs(tree, (*it).first, n, answer, subTree, distance, isVisited);
			subTree[vertex] += subTree[(*it).first];
		}
	}
	answer += (((subTree[vertex] * (n - subTree[vertex])) % modul) * distance[vertex]) % modul;
}
void getAnswer(long long& answer, vector<vector<pair< long long, long long >>>& tree, long long n, long long*& subTree, long long*& distance, vector<bool>& isVisited)
{
	dfs(tree, 0, n, answer, subTree, distance, isVisited);
	answer = (answer * 2) % modul;
}
int main()
{
	long long n, temp, temp2, temp3;
	long long answer = 0;
	cin >> n;


	vector<vector<pair< long long, long long >>> tree(n);
	long long* subTree = new long long[n], * distance = new long long[n];
	for (long long i = 0; i < n; i++)
	{
		subTree[i] = 1;
		distance[i] = 0;
	}
	vector<bool>isVisited(n, false);


	for (long long i = 0; i < n - 1; i++)
	{
		cin >> temp;
		cin >> temp2;
		cin >> temp3;
		tree[temp - 1].push_back({ temp2 - 1, temp3 });
		tree[temp2 - 1].push_back({ temp - 1, temp3 });
	}


	getAnswer(answer, tree, n, subTree, distance, isVisited);
	cout << answer;
	return 0;
}