#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long L;
struct suffix
{
	L index;
	L rank;
	L rank2;
};

bool comparison(suffix& a, suffix& b)
{
	return (a.rank == b.rank) ? (a.rank2 < b.rank2 ? 1 : 0) : (a.rank < b.rank ? 1 : 0);
}


vector<L> getSArr(string s)
{
	L sLen = s.length();
	vector<suffix> sf(sLen);
	for (L i = 0; i < sLen; i++)
	{
		sf[i].index = i;
		sf[i].rank = s[i];
		sf[i].rank2 = i + 1 < sLen ? s[i + 1] - 'a' : sf[i].rank2 = -1;
	}
	sort(sf.begin(), sf.end(), comparison);
	vector<L> indexInSf(sLen);
	for (L k = 4; k < 2 * sLen; k *= 2)
	{
		L rank = 0;
		L prevRank = sf[0].rank;
		sf[0].rank = rank;
		indexInSf[sf[0].index] = 0;
		for (L i = 1; i < sLen; i++)
		{
			if (sf[i].rank == prevRank && sf[i].rank2 == sf[i - 1].rank2)
			{
				prevRank = sf[i].rank;
				sf[i].rank = rank;
			}
			else
			{
				rank++;
				prevRank = sf[i].rank;
				sf[i].rank = rank;
			}
			indexInSf[sf[i].index] = i;
		}
		for (L i = 0; i < sLen; i++)
		{
			L nIndex = sf[i].index + k / 2;
			sf[i].rank2 = nIndex < sLen ? sf[indexInSf[nIndex]].rank : sf[i].rank2 = -1;
		}
		sort(sf.begin(), sf.end(), comparison);
	}
	vector<L> resultArr(sLen);
	for (L i = 0; i < sLen; i++)
		resultArr[i] = sf[i].index;
	return resultArr;

}

vector<L> getLCP(string s, vector<L>& sf)
{
	L n = sf.size();
	vector<L> LCP(n, 0);
	vector<L> pos(n, 0);
	for (L i = 0; i < n; i++)
		pos[sf[i]] = i;
	L k = 0;
	for (L i = 0; i < n; i++)
	{
		if (pos[i] == n - 1)
		{
			k = 0;
			continue;
		}
		L j = sf[pos[i] + 1];
		L tempMax = max(i + k, j + k);
		while (tempMax < n && s[i + k] == s[j + k])
		{
			k++;
			tempMax = max(i + k, j + k);
		}
		LCP[pos[i]] = k;
		if (k > 0)
			k--;
	}
	return LCP;
}
L getNumberOfSubstrings(string s)
{
	L sLen = s.length();
	vector<L> arrOfSf = getSArr(s);
	vector<L> LCP = getLCP(s, arrOfSf);
	L sum = 0;
	for (L i = 0; i < sLen; i++)
	{
		sum += LCP[i];
	}
	L result = sLen * (sLen + 1) / 2;
	result -= sum;
	return result;
}

int main()
{
	string s;
	cin >> s;
	cout << getNumberOfSubstrings(s);

}