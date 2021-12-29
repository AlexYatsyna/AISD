#include <iostream>

using namespace std;


int main()
{
	string s;
	cin >> s;
	bool isExc = true;
	for (long i = 0; i < s.length(); i++)
	{
		if (s[0] != s[i])
		{
			isExc = false;
			break;
		}
	}
	if (isExc)
	{
		cout << -1;
		return 0;
	}
	if (equal(s.begin(), s.begin() + s.size() / 2, s.rbegin(), s.rbegin() + s.size() / 2))
	{
		cout << s.length() - 1;
		return 0;
	}
	else
	{
		cout << s.length();
		return 0;
	}
}