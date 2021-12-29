#include <iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int* mass = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> mass[i];
	}
	sort(mass, mass + n);
	if ((long)(mass[0]) * mass[1] < (long)(mass[n - 1]) * mass[n - 2])
	{
		cout << (long)(mass[n - 1]) * mass[n - 2];
	}
	else
	{
		cout << (long)(mass[0]) * mass[1];
	}
}
