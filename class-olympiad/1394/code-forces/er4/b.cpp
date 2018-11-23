#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

const int maxn = 1000;
int a[maxn];
int n;
bool d[maxn][maxn];
int sumi = 0;

int getans()
{
	memset(d, 0, sizeof d);
	for(int i = 0; i <= n - 1; i++)
		d[i][0] = true;
	for(int i = 1; i < n; i++)
		for(int j = 1; j <= sumi; j++)
		{
			d[i][j] = d[i - 1][j];
			if(j - a[i - 1] >= 0)
				d[i][j] |= d[i - 1][j - a[i - 1]];
		}
	int co = 0;
	for(int i = 0; i <= sumi; i++)
	{
		if(d[n - 1][i])
		{
			co++;
		}
	}
	return co * 2;
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i], sumi += a[i];
	int ans = getans();
	for(int i = 0; i < n - 1; i++)
	{
		swap(a[i], a[n - 1]);
		ans = max(ans, getans());
	}
	cout << ans << endl;
}
