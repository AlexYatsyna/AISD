#include <iostream>
#include <cmath>
using namespace std;


int main()
{
	int n, m, x1, x2, y1, y2;
	cin >> n;
	cin >> m;
	cin >> x1;
	cin >> y1;
	cin >> x2;
	cin >> y2;
	fabs(x1 - x2) == fabs(y1 - y2) ? cout << "NO" : cout << "YES";
}