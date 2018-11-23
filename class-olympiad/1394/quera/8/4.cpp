#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;
const int maxn = 102, maxm = (1<<16) + 1000, inf = 1e9;
long long d[2][maxn][maxm];
long long n, m;
long long a[maxn][maxn];
long long dis[maxn];
long long getmin(long long j, long long i)
{
	int co = 0;
	long long mini = inf;
	while(j > 0)
	{
		if(j % 2 == 1)
			mini = min(mini, a[co][i]);
		j/=2;
		co++;
	}
	return mini;

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		cin >> dis[i];
		for(int j = 0; j < m; j++)
			cin >> a[i][j];
	}
	d[1][0][0] = dis[0];
	for(int i = 1; i < (1<<m); i++)
	{
		d[1][0][i] = dis[0];
		for(int k = 0; k < m; k++)
			if(((i>>k)&1) == 1)
				d[1][0][i] += a[0][k];
		d[0][0][i] = inf;
	}
	for(int i = 1; i < n; i++)
	{
		d[0][i][0] = 0;
		d[1][i][0] = dis[i];
		for(int j = 1; j < (1<<m); j++)
		{
			d[0][i][j] = min(d[0][i - 1][j], d[1][i - 1][j]);
			d[1][i][j] = dis[i] + min(d[0][i - 1][j], d[1][i - 1][j]);
			for(int k = 0; k < m; k++)
				if(((j >> k)&1) == 1)
					d[1][i][j] = min(d[1][i][j], min(dis[i]+d[0][i][j - (1<<k)] + a[i][k], a[i][k] + d[1][i][j - (1<<k)]));
		}
	}

	long long ans = min(d[0][n - 1][(1<<m) - 1], d[1][n - 1][(1<<m)-1]);
	cout << ans << endl;
}
