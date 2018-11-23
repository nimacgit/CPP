#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;
int n ,k ,m;
const int maxn = 2000;
bool a[maxn][maxn];


int main()
{
	cin >> n >> m >> k;
	for(int i = 0, x, y; i < k; i++)
		{
			cin >> x >> y;
			x--;
			y--;
			a[x][y] = true;
		}
	if(k == n * m)
	{
		if(k % 2 == 0)
		{
			cout << -1 << endl;
			return 0;
		}
		else
		{
			cout << 0 << endl;
			return 0;
		}
	}
	if(k % 2 == 1)
	{
		cout << 0 << endl;
		return 0;
	}
	for(int i = 0; i < n; i++)	
		for(int j = 0; j < m; j++)
			if(!a[i][j])
			{
				cout << 1 << endl;
				cout << i + 1 << " " << j + 1 << endl;
				return 0;
			}
}
