#include <iostream>

using namespace std;

long findMaxValue(long* A, long n)
{
	long max = 0;
	for (long i = 0; i < n; i++)
	{
		if (A[i] > max)
			max = A[i];
	}
	return max;
}
int main()
{
	long  counter = 0;
	long  n;
	cin >> n;
	long* A = new long[n];
	for (long i = 0; i < n; i++)
		cin >> A[i];
	long maxValue = findMaxValue(A, n);
	if (A[0] != maxValue)
		counter = maxValue - A[0];
	for (long i = 0; i < n - 1; i++)
		if (A[i] > A[i + 1])
			counter += A[i] - A[i + 1];
	cout << counter;
}