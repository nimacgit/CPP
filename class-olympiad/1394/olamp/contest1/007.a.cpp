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
const int maxn = 10 * 1000;
int a[maxn + 100][maxn + 100];
int d[maxn + 100][maxn + 100];
int n;

void dyn(int &x, int &y)
{
	for(int i = 0; i < n; i++)
	{
		if(a[i][0])
		{
			d[i][0] = 1;
			x = i;
			y = 0;
		}
		else
			d[i][0] = 0;
		if(a[0][i])
		{
			d[0][i] = 1;
			x = 0;
			y = i;
		}
		else
			d[0][i] = 0;
	}
	for(int i = 1; i < n; i++)
	{
		for(int j = 1; j < n; j++)
		{
			if(a[i][j])
			{
				int len = min(d[i - 1][j], d[i][j - 1]);
				if(d[i - 1][j] == d[i][j - 1])
				{
					if(a[i - len][j - len])
						d[i][j] = len + 1;
					else
						d[i][j] = len;
				}
				else
				{
					d[i][j] = len + 1;
				}
			}
			else
				d[i][j] = 0;
			if(d[i][j] > d[x][y])
			{
				x = i;
				y = j;
			}
		}
	}
}

int main()
{
	cin >> n;
	string s;
	for(int i = 0; i < n; i++)
	{
		cin >> s;
		for(int j = 0; j < n; j++)
		{
			if(s[j] == '0')
				a[i][j] = false;
			else
				a[i][j] = true;
		}
	}
	int x = 0,  y = 0;
	dyn(x, y);
	cout << d[x][y] << " " << y - d[x][y] + 2 << " " << x - d[x][y] + 2 << endl;


}
