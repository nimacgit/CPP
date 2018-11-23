#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

const int maxn = 300;
long long d[maxn][maxn];
bool use[maxn][maxn];
long long mo = 1e9 + 7;
pie p[maxn];
int n;

bool isok(pie p1, pie p2, pie p3, pie p4)
{
	int A0 = p1.F, B0 = p1.S;
	int A1 = p2.F, B1 = p2.S;
	int A2 = p3.F, B2 = p3.S;
	int A3 = p4.F, B3 = p4.S;
	if(((A2-A0)*(B1-B0) - (B2-B0)*(A1-A0)) * ((A3-A0)*(B1-B0) - (B3-B0)*(A1-A0)) < 0 && ((A0-A2)*(B3-B2) - (B0-B2)*(A3-A2)) * ((A1-A2)*(B3-B2) - (B1-B2)*(A3-A2)) < 0)
		return false;
	return true;
}


long long ans(int i, int j)
{
	if(use[i][j])
		return d[i][j];
	use[i][j] = true;
	bool flag = true;
	int u = 0, l = 0, r = 0, d = 0
	for(int k = 0; k < n - 2; k++)
	{
		if(k != i && k != i - 1 && k != j - 1 && k != j)
			if(!isok(p[i], p[j], p[k], p[k + 1]))
				flag = false;
		for(int k = i; k < j; k++)
			if(p[i].F < )
	}
	if(!flag)
		return d[i][j] = 0;
	if(j - i <= 2)
		return d[i][j] = 1;
	d[i][j] = 0;
	for(int k = i + 1; k < j; k++)
	{
		d[i][j] += (ans(i, k)*ans(k, j)) % mo;
		d[i][j] %= mo;
	}
	return d[i][j];

}


int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		p[i] = mp(x, y);
	}
	cout << ans(0, n - 1) << endl;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cerr << i << " " << j << " " << d[i][j] << endl;
	cerr << isok(p[0], p[1], p[1], p[2]) << " " << isok(p[0], p[1], p[2], p[3]) << " " << isok(mp(0, 0), mp(1, 1), mp(1, 0), mp(0, 1)) << endl;
}
