#include <iostream>
using namespace std;
long long modul = 1e9 + 7;
long long** multiAdjacencyList(long long** matrix1, long long** matrix2, const int n)
{
	long long** result = new long long* [n];
	for (int i = 0; i < n; i++)

		result[i] = new long long[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			result[i][j] = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int q = 0; q < n; q++)
				result[i][j] = (result[i][j] + (matrix1[i][q] * matrix2[q][j]) % modul) % modul;
	return result;
}
long long** powAdjacencyList(long long** adjacencyList, long long power, const int n)
{
	if (power == 0)
	{
		long long** E = new long long* [n];
		for (long long i = 0; i < n; i++)
			E[i] = new long long[n];
		for (long long i = 0; i < n; i++)
		{
			for (long long j = 0; j < n; j++)
			{
				i == j ? E[i][j] = 1 : E[i][j] = 0;
			}

		}
		return E;
	}
	else
		if (power % 2 == 1)
		{
			return multiAdjacencyList(powAdjacencyList(adjacencyList, power - 1, n), adjacencyList, n);
		}
		else
		{
			long long** tempMatrix = powAdjacencyList(adjacencyList, power / 2, n);
			return multiAdjacencyList(tempMatrix, tempMatrix, n);
		}
}

int main()
{
	long long n, m, start, finish, length, temp, temp2;
	cin >> n;
	cin >> m;
	cin >> start;
	cin >> finish;
	cin >> length;
	start--;
	finish--;
	long long** adjacencyList = new long long* [n];
	long long** answer;
	for (int i = 0; i < n; i++)
		adjacencyList[i] = new long long[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			adjacencyList[i][j] = 0;

	for (int i = 0; i < m; i++)
	{
		cin >> temp;
		cin >> temp2;
		temp--;
		temp2--;
		adjacencyList[temp][temp2] += 1;
		adjacencyList[temp2][temp] += 1;
	}
	if (length == 0)
	{
		if (start == finish)
		{
			cout << 1;
			return 0;
		}
		else
		{
			cout << 0;
			return 0;
		}
	}
	else
		answer = powAdjacencyList(adjacencyList, length, n);
	cout << answer[start][finish];
	return 0;
}