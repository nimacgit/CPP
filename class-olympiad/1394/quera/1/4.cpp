#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

const int maxn = 1e3 + 100;
bool d[maxn][maxn][2];
bool seen[maxn][maxn][2];
int n, m;
bool mat[maxn][maxn];


int p(int a)
{
	if(a == 0)
		return n - 1;
	else
		return a - 1;
}
int ne(int a)
{
	if(a == n - 1)
		return 0;
	else
		return a + 1;
}

bool g(int s, int t, int pos)
{
	if(seen[s][t][pos])
		return d[s][t][pos];
	seen[s][t][pos] = true;
	if(p(s) == t || ne(t) == s)
		return d[s][t][pos] = true;
	if(pos == 0)
	{
		if(mat[s][p(s)])
			d[s][t][pos] |= g(p(s), t, 0);
		if(mat[s][ne(t)])
			d[s][t][pos] |= g(s, ne(t), 1);
	}
	else
	{
		if(mat[t][ne(t)])
			d[s][t][pos] |= g(s, ne(t), 1);
		if(mat[t][p(s)])
			d[s][t][pos] |= g(p(s), t, 0);
	}
	return d[s][t][pos];
}

void pr(int s, int t, int pos)
{
	if(ne(t) == s || p(s) == t)
		return;
	if(pos)
	{
			if(mat[t][ne(t)] && d[s][ne(t)][pos])
			{
				cout << ne(t) + 1 << endl;
				pr(s, ne(t), pos);
				return;
			}
			if(mat[p(s)][t] && d[p(s)][t][0])
			{
				cout << p(s) + 1 << endl;
				pr(p(s), t, 0);
				return;
			}
	}
	else
	{
			if(mat[s][ne(t)] && d[s][ne(t)][pos + 1])
			{
				cout << ne(t) + 1 << endl;
				pr(s, ne(t), pos + 1);
				return;
			}
			if(mat[s][p(s)] && d[p(s)][t][0])
			{
				cout << p(s) + 1 << endl;
				pr(p(s), t, 0);
				return;
			}	
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int x, y, i = 0; i < m; i++)
	{
		cin >> x >> y;
		x--;
		y--;
		mat[x][y] = mat[y][x] = true;
	}
	for(int i = 0; i < n; i++)
	{
		if(g(i, i , 0))
		{
			cout << i + 1 << endl;
			pr(i, i, 0);
			return 0;
		}
	}
	cout << -1 << endl;
	

}
