#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;
void checkStartAndFinish(long long& start, long long& finish)
{
	if (start > finish)
		swap(start, finish);
}
long getDistance(vector<vector<pair< long long, long long>>>& adjacencyList, long long n, long long start, long long finish)
{
	checkStartAndFinish(start, finish);
	long long  minValue;
	int minIndex;
	vector< long long> distance(n, LLONG_MAX);
	vector<bool>isVisited(n, false);
	distance[start - 1] = 0;

	for (int k = 0; k < n; k++)
	{
		minValue = LLONG_MAX;
		for (int i = 0; i < n; i++)
		{
			if (!isVisited[i] && (distance[i] <= minValue))
			{
				minValue = distance[i];
				minIndex = i;
			}
		}
		isVisited[minIndex] = true;
		for (int i = 0; i < adjacencyList[minIndex].size(); i++)
		{
			distance[adjacencyList[minIndex][i].first] = min(distance[adjacencyList[minIndex][i].first], distance[minIndex] + adjacencyList[minIndex][i].second);
		}
	}
	return distance[finish - 1];
}
int main()
{
	long long n, m, start, finish, temp, temp2, temp3;
	cin >> n >> m;
	vector<vector<pair< long long, long long >>> adjacencyList(n);
	for (int i = 0; i < m; i++)
	{
		cin >> temp;
		cin >> temp2;
		cin >> temp3;
		adjacencyList[temp - 1].push_back(make_pair(temp2 - 1, temp3));
		adjacencyList[temp2 - 1].push_back(make_pair(temp - 1, temp3));
	}
	cin >> start >> finish;
	if (start == finish)
	{
		cout << 0;
		return 0;
	}
	cout << getDistance(adjacencyList, n, start, finish);
	return 0;
}