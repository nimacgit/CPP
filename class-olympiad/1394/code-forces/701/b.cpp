#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

const int maxn = 1e5+1000;
long long ans, n, m, ca, ra;
bool c[maxn], r[maxn];
int main()
{
	cin >> n >> m;
	ca = ra = 0;
	ans = n * n;
	for(int i = 0, x, y; i < m; i++)
	{
		int tempc = 0, tempr =  0;
		cin >> x >> y;
		x--;
		y--;
		if(!c[x] && !r[y])
			ans++;
		if(!c[x])
		{
			c[x] = true;
			ans -= n - ra;
			tempc = 1;
		}
		if(!r[y])
		{
			r[y] = true;
			ans -= n - ca;
			tempr = 1;
		}
		ra += tempr;
		ca += tempc;
		cout << ans << " ";
	}
	cout << endl;
}
