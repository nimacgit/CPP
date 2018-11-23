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
const int maxn = 500;
int h, w, q;
long long  d[maxn + 100][maxn + 100];
char a[maxn + 100][maxn + 100];
string s;

int main()
{
	cin >> h >> w;
	for(int i = 0; i < h; i++)
	{
		d[0][i] = d[i][0] = 0;
		cin >> s;
		for(int j = 0; j < w; j++)
		{
			a[i][j] = s[j];
			if(a[i][j] == '#')
				d[i + 1][j + 1] = d[i][j + 1] + d[i + 1][j] - d[i][j];
			else
			{
				int co = 0;
				if(i != 0 && a[i - 1][j] == '.')
				{
					co++;
				}
				 if(j != 0 && a[i][j - 1] == '.')
				{
					co++;
				}
				
				d[i + 1][j + 1] = d[i][j + 1] + d[i + 1][j] - d[i][j] + co;
			}
				
		}
	}
	cin >> q;
	for(int i = 0; i < q; i++)
	{
		int r1, r2, c1, c2, co = 0;
		scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
		for(int i = r1; i <= r2 && c1 > 1; i++)
			if(a[i - 1][c1 - 1] == '.' && a[i - 1][c1 - 2] == '.')
				co++;
		for(int i = c1; i <= c2 && r1 > 1; i++)
			if(a[r1 - 1][i - 1] == '.' && a[r1 - 2][i - 1] == '.')
				co++;
		cout << d[r2][c2] - d[r2][c1 - 1] - d[r1 - 1][c2] + d[r1 - 1][c1 - 1] - co << endl;
	}
	
}

