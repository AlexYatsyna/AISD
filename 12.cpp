#include <iostream>

using namespace std;


int main()
{
	long n;
	cin >> n;
	n % 10 == 0 ? cout << "NO" : cout << n % 10;
}