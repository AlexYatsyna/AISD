#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, finishX, finishY;
bool checkAnswer(int x, int y)
{
	if (x == finishX && y == finishY)
		return true;
	else
		return false;
}
void searchAnswer(queue<int>& qX, queue<int>& qY, int**& matrix, int x, int y, bool& isFound)
{
	isFound = checkAnswer(x, y);
	if (isFound)
		return;

	if (x + 2 < n && y + 1 < m)
	{
		if (matrix[x + 2][y + 1] == 0)
		{
			qX.push(x + 2);
			qY.push(y + 1);
			matrix[x + 2][y + 1] = matrix[x][y] + 1;
		}
	}

	if (x + 2 < n && y - 1 >= 0)
	{
		if (matrix[x + 2][y - 1] == 0)
		{
			qX.push(x + 2);
			qY.push(y - 1);
			matrix[x + 2][y - 1] = matrix[x][y] + 1;
		}
	}

	if (x + 1 < n && y - 2 >= 0)
	{
		if (matrix[x + 1][y - 2] == 0)
		{
			qX.push(x + 1);
			qY.push(y - 2);
			matrix[x + 1][y - 2] = matrix[x][y] + 1;
		}
	}

	if (x + 1 < n && y + 2 < m)
	{
		if (matrix[x + 1][y + 2] == 0)
		{
			qX.push(x + 1);
			qY.push(y + 2);
			matrix[x + 1][y + 2] = matrix[x][y] + 1;
		}
	}

	if (x - 2 >= 0 && y - 1 >= 0)
	{
		if (matrix[x - 2][y - 1] == 0)
		{
			qX.push(x - 2);
			qY.push(y - 1);
			matrix[x - 2][y - 1] = matrix[x][y] + 1;
		}
	}

	if (x - 2 >= 0 && y + 1 < m)
	{
		if (matrix[x - 2][y + 1] == 0)
		{
			qX.push(x - 2);
			qY.push(y + 1);
			matrix[x - 2][y + 1] = matrix[x][y] + 1;
		}
	}

	if (x - 1 >= 0 && y - 2 >= 0)
	{
		if (matrix[x - 1][y - 2] == 0)
		{
			qX.push(x - 1);
			qY.push(y - 2);
			matrix[x - 1][y - 2] = matrix[x][y] + 1;
		}
	}

	if (x - 1 >= 0 && y + 2 < m)
	{
		if (matrix[x - 1][y + 2] == 0)
		{
			qX.push(x - 1);
			qY.push(y + 2);
			matrix[x - 1][y + 2] = matrix[x][y] + 1;
		}
	}
}

int main()
{
	bool isFound = false;
	cin >> n;
	cin >> m;
	cin >> finishX;
	cin >> finishY;
	finishX--;
	finishY--;

	bool** isVisited = new bool* [n];
	int** matrix = new int* [n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			matrix[i][j] = 0;
	queue<int> qX;
	queue<int> qY;
	qX.push(0);
	qY.push(0);

	for (; !isFound && !qX.empty() && !qY.empty();)
	{
		searchAnswer(qX, qY, matrix, qX.front(), qY.front(), isFound);
		qX.pop();
		qY.pop();
	}
	if (isFound)
		cout << matrix[finishX][finishY];
	else
		cout << "NEVAR";

	return 0;
}
