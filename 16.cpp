#include <iostream>
using namespace std;
long numberOfDigit(long n)
{
	int i = 1;
	while ((n / 10) != 0) {
		i++;
		n /= 10;
	}
	return i;
}
long* getArray(long n) {
	long i, number = n;
	i = numberOfDigit(n);
	int k = i - 1;
	long* arr = new long[i];
	while (i != 0)
	{
		arr[k] = number % 10;
		number /= 10;
		i--; k--;
	}
	return arr;
}
int main()
{
	long n;
	long* mass;
	cin >> n;
	if (n > -10 && n < 10)
	{
		cout << -1;
		return 0;
	}
	mass = getArray(n);
	int  current = -1;
	int swap = -1;
	int number = numberOfDigit(n) - 1;


	for (int i = number; i >= 0; i--)
	{

		for (int j = number; j > i; j--)
		{
			if (mass[j] > mass[i])
			{
				current = i;
				swap = j;
				break;
			}
		}
		if (current >= 0 || swap >= 0) break;

	}

	if (current >= 0 || swap >= 0) {

		int buf = mass[current];
		mass[current] = mass[swap];
		mass[swap] = buf;

		for (int i = number; i > current; i--)
		{

			for (int j = number; j > i; j--)
			{
				if (mass[j] < mass[i])
				{
					int buffer = mass[i];
					mass[i] = mass[j];
					mass[j] = buffer;

				}
			}
		}
		for (int i = 0; i <= number; i++)
		{
			cout << mass[i];
		}
	}
	else
		cout << -1;

}