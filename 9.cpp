#include <iostream>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int q, l, r;
	bool* indikator = new bool[s.length() + 1]{};
	cin >> q;
	while (q > 0)
	{
		cin >> l;
		cin >> r;
		if (l > r)
		{
			int temp = l;
			l = r;
			r = temp;
		}
		indikator[l - 1] = !indikator[l - 1];
		indikator[r] = !indikator[r];

		q--;
	}
	bool temp = false;
	for (int i = 0; i < s.length(); i++)
	{
		if (indikator[i])
			temp = !temp;
		if (temp)
		{
			if ((int)s[i] > 96 && (int)s[i] < 123)
			{
				s[i] = char(s[i] - 32);
				continue;
			}
			if ((int)s[i] < 91 && (int)s[i]>64)
			{
				s[i] = char(s[i] + 32);
				continue;
			}
		}

	}
	cout << s;
}