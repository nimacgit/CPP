#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

const int maxl = 1e7;
int lg[maxl];
int n, m, numn, numm;
int use[10];
long long pw[10];

void pre()
{
	for(int i = 7; i < maxl; i++)
		lg[i] = lg[i / 7] + 1;
	pw[0] = 1;
	for(int i = 1; i < 10; i++)
		pw[i] = pw[i - 1] * 7;
}

long long makem(int pos)
{
	long long ans = 0;
	if(pos == -1)
		return 1;
	for(int i = 0; i * pw[pos] <= numm && i < 7; i++)
	{
		if(!use[i])
		{
			numm -= i * pw[pos];
			use[i] = true;
			ans += makem(pos - 1);
			use[i] = false;
			numm += i * pw[pos];
		}
	}
	return ans;

}

long long maken(int pos)
{
	long long ans = 0;
	if(pos == -1)
		return makem(lg[numm]);
	for(int i = 0; i * pw[pos] <= numn && i < 7; i++)
	{
		if(!use[i])
		{
			numn -= i * pw[pos];
			use[i] = true;
			ans += maken(pos - 1);
			use[i] = false;
			numn += i * pw[pos];
		}
	}
	return ans;
}


int main()
{
	pre();
	memset(use, 0, sizeof use);
	cin >> n >> m;
	n--;
	m--;
	numn = n;
	numm = m;
	if(n > pw[9] || m > pw[9] || lg[n] + lg[m] > 9)
	{
		cout << 0 << endl;
		return 0;
	}
	cout << maken(lg[numn]) << endl;
}
