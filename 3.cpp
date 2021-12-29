#include <iostream>
#include <algorithm>
using namespace std;
long modul = 1e9 + 7;
long maxMultiplication(long* sequence, long n, long k)
{
	long result = 1;
	sort(sequence, sequence + n);
	if (sequence[n - 1] < 0 && k % 2 == 0)
	{
		for (long i = 0; i < k; i++)
		{
			result *= sequence[i];
			result %= modul;
		}
	}
	else
		if (sequence[n - 1] < 0 && k % 2 != 0)
		{
			for (long i = n - 1; i >= n - k; i--)
			{
				result *= sequence[i];
				result %= modul;
			}
		}
		else
		{
			int rBorder;
			int lBorder = 0;
			if (k % 2 != 0)
			{
				result *= sequence[n - 1];
				result %= modul;
				k--;
				rBorder = n - 2;
			}
			else
				rBorder = n - 1;
			k /= 2;
			for (int i = 0; i < k; i++)
			{
				if (sequence[lBorder] * sequence[lBorder + 1] > sequence[rBorder] * sequence[rBorder - 1])
				{
					long t = (sequence[lBorder] * sequence[lBorder + 1]) % modul;
					result = t * result % modul;
					lBorder += 2;
				}
				else
				{
					long t = (sequence[rBorder] * sequence[rBorder - 1]) % modul;
					result = result * t % modul;
					rBorder -= 2;
				}
			}
		}

	result = result < 0 ? result + modul : result;
	return result;
}

int main()
{
	long n, k;
	long* sequence;
	cin >> n;
	cin >> k;
	sequence = new long[n];
	for (int i = 0; i < n; i++)
	{
		cin >> sequence[i];
	}
	cout << maxMultiplication(sequence, n, k);



}