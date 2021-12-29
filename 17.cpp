#include <iostream>
using namespace std;
int main()
{
	int n;
	bool f = false, s = false, th = false, one = false, full = false, fs = false, fth = false, sth = false;
	cin >> n;
	int a = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		if (a == 1021)
			f = true;
		if (a == 1031)
			s = true;
		if (a == 1033)
			th = true;
		if (a == 1)
			one = true;
		if (a == 1087388483)
			full = true;
		if (a == 1052651)
			fs = true;
		if (a == 1054693)
			fth = true;
		if (a == 1065023)
			sth = true;
	}
	if ((f && s && th) || (one && full) || (fs && th) || (fth && s) || (sth && f) || full)
		cout << "YES";
	else
		cout << "NO";


}