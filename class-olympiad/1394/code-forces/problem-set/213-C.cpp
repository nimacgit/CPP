#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair

using namespace std;

typedef pair<int, int> pie;
const int maxn = 303;
int a[maxn][maxn];
int d[maxn][maxn][2 * maxn];
int n, m;
const int minf = -1e9;
void dyn()
{
	int co = 0;
	d[0][0][0] = a[0][0];
	for(int i = 1; i < 2*n - 1; i++)
	{
		if(i >= n)
			co += 2;
		for(int x1 = 0; x1 <= i - co; x1++)
			for(int x2 = x1; x2 <= i - co; x2++)
			{
				int uu = minf, ll = minf, ul = minf, lu = minf, ai;

				if(i < n)
				{
					if(x1 == x2)
					{

						ai = a[x1][i - x1];
						if(x1 < i)
						{
							ul = d[max(0, x1 - 1)][x2][i - 1];
							ll = d[x1][x2][i - 1];
						}
						uu = d[max(0, x1 - 1)][max(0, x2 - 1)][i - 1];
					}
					else
					{

						ai = a[x1][i - x1] + a[x2][i - x2];
						if(x2 < i)
						{
							if(x1 < i)
								ll = d[x1][x2][i - 1];
							ul = d[max(0, x1 - 1)][x2][i - 1];
						}
						if(x1 < i)
							lu = d[x1][max(0, x2 - 1)][i - 1];
						uu = d[max(0, x1 - 1)][max(0, x2 - 1)][i - 1];
					}
				}
				else
				{
					if(x1 == x2)
					{

						ai = a[i - n + 1 + x1][n - x1 - 1];
						uu = d[x1][x2][i - 1];
						ll = d[x1 + 1][x2 + 1][i - 1];
						ul = d[x1][x2 + 1][i - 1];
					}
					else
					{
						uu = d[x1][x2][i - 1];
						ll = d[x1 + 1][x2 + 1][i - 1];
						lu = d[x1 + 1][x2][i - 1];
						ul = d[x1][x2 + 1][i - 1];
						ai = a[i - n + 1 + x1][n - x1 - 1] + a[i - n + 1 + x2][n - x2 - 1];
					}
				}
				d[x1][x2][i] = max(max(ll,uu), max(lu, ul)) + ai;
			}
	}
}



int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
	dyn();
	cout << d[0][0][2*n - 2] << endl;
}
