#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

const int maxn = 1e6 + 1000;
int a[maxn];
int par[maxn];
int n, m;

int gpar(int a)
{
	if(par[a] == a)
		return a;
	return par[a] = gpar(par[a]);
}

void merg(int a, int b)
{
	a = gpar(a);
	b = gpar(b);
	if(a != b)
		par[a] = b;
}

vector<int> mv[maxn], mc[maxn];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		par[i] = i;
	}

	for(int i = 0, x, y; i < m; i++)
	{
		cin >> x >> y;
		x--;
		y--;
		merg(x, y);
	}
	for(int i = 0; i < n; i++)
	{
		mv[gpar(i)].push_back(i);
		mc[gpar(i)].push_back(a[i]);
	}
	for(int i = 0; i < n; i++)
	{
		if(mv[i].size() != 0)
		{
		sort(mv[i].begin(), mv[i].end());
		sort(mc[i].begin(), mc[i].end());
		for(int j = 0; j < mc[i].size(); j++)
		{
			a[mv[i][j]] = mc[i][mc[i].size() - 1 - j];
		}
		}
	}
	for(int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
	
}
