#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

int n, m;
int ans = 1000000;
int have = 0;
bool a[1000][1000];

int getans(int x, int y)
{
	int g = 100000;
	int h = 0;
	for(int i = 0; i < n - x + 1; i++)
	{
		for(int j = 0; j < n - y + 1; j++)
		{
				h = 0;
				for(int k = 0; k < x; k++)
					for(int l = 0; l < y; l++)
						h += a[k + i][l + j];
				g = min(g, m - h);
		}
	}
	return g;

}

int main()
{
	cin >> n >> m;
	for(int i = 0, x, y; i < m; i++)
	{
		cin >> x >> y;
		x--;
		y--;
		a[x][y] = true;
	}
	for(int i = 1; i <= m; i++)
	{
		if(m % i == 0 && m / i <= n && i <= n)
			ans = min(ans, getans(m / i, i));
	}
	cout << ans << endl;
}
