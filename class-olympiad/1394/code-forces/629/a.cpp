#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second
using namespace std;

typedef pair<int, int> pie;

const int maxn = 5000;
const int maxd = 400;
int n;
char m[maxn], f[maxn];
pie can[maxd][maxd];
pie sum[maxn][maxn];

int main()
{
	
	cin >> n;
	char c;
	for(int i = 0, x, y; i < n; i++)
	{
		cin >> c;
		cin >> x >> y;
		x--;
		y--;
		if(c == 'F')
			can[x][y] = mp(can[x][y].F + 1, can[x][y].S);
		else
			can[x][y] = mp(can[x][y].F, can[x][y].S + 1);
	}
	for(int i = 0; i < maxd; i++)
	{
		for(int j = maxd - 1; j >= i; j--)
		{
			if(j == maxd - 1)
				sum[i][j] = can[i][j];
			else
			{
				sum[i][j] = mp(sum[i][j + 1].F, sum[i][j + 1].S);
				for(int k = i; k >= 0; k--)
				{
					sum[i][j].F += can[k][j].F;
					sum[i][j].S += can[k][j].S;
				}
			}
		}
	}
	int maxi = 0;
	for(int i = 0; i < maxd; i++)
	{
		for(int j = i; j < maxd; j++)
		{
			maxi = max(maxi, min(sum[i][j].F, sum[i][j].S));
		}

	}
	cout << 2*maxi << endl;
}
