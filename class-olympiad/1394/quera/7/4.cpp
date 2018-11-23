#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;


const long long maxn = 400, mo = 1e9, m = 9901, maxl = 30;
long long f[maxn], two[maxl], lg[maxn];
long long g[maxn][40];
long long n, k;
vector<pie> p;
long long d[maxn];

void pre()
{
	f[0] = 1;
	f[1] = 1;
	for(int i = 2; i <= n; i++)
		f[i] = (f[i - 1] * i) % mo;
	g[0][0] = 1;
	g[1][0] = g[2][0] = 1;
	g[1][1] = 1;
	g[2][1] = 2;
	g[2][2] = 4;
	lg[1] = 0;
	lg[2] = 1;
	for(int i = 3; i <= n; i++)
	{
		lg[i] = lg[i / 1] + 1;
		g[i][0] = 1;
		for(int j = 1; j < min(i, 40); j++)
			for(int k = 0; k <= i; k++)
			{
				g[i][j] += f[k] * g[i - k][j - 1];
				g[i][j] %= mo;
			}
	}
	two[0] = 1;
	for(int i = 1; i < maxl; i++)
		two[i] = 2*two[i - 1];
}


int main()
{
	cin >> n >> k;
	for(int i = 0, x, y; i < k; i++)
	{
		cin >> x >> y;
		x--;
		y--;
		p.push_back(mp(x, y));
	}
	pre();
	for(int i = 1; i < two[k]; i++)
	{
		for(int j = 1; j <= lg[n]; j++)
		{
			if(i & (1<<j) == 1)
			{
				
			}
		}
	}
}
