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
const int maxn = 1000 * 10 + 100;
const int maxl = 20;
int par[maxn][maxl];
long long dis[maxn];
vector <pie> adj[maxn];
int pw[maxl];
bool seen[maxn];
int h[maxn];
int n, m, t;
string s;


void pre()
{
	pw[0] = 1;
	for(int i = 1; i < maxl; i++)
		pw[i] = pw[i - 1] * 2;
	for(int i = 0; i < n; i++)
	{
		h[i] = 0;
		seen[i] = false;
		adj[i].clear();
	}
}

void dfs(int v)
{
	seen[v] = true;
	for(int i = 1; i < maxl; i++)
		par[v][i] = par[par[v][i - 1]][i - 1];
	for(int i = 0; i < adj[v].size(); i++)
	{
		int u = adj[v][i].F;
		if(!seen[u])
		{
			dis[u] = dis[v] + adj[v][i].S;
			h[u] = h[v] + 1;
			par[u][0] = v;
			dfs(u);
		}
	}
}

int lca(int x, int y)
{
	if(h[x] >= h[y])
		swap(x, y);
	for(int i = maxl - 1; i >= 0; i--)
		if(h[par[y][i]] >= h[x])
			y = par[y][i];
	if(y == x)
		return x;
	for(int i = maxl - 1; i >= 0; i--)
		if(par[x][i] != par[y][i])
		{
			x = par[x][i];
			y = par[y][i];
		}
	return par[x][0];
}


int kth(int x, int y, int k)
{
	int fa = lca(x, y);
	if(k == 1)
		return x + 1;
	if(k == h[x] + h[y] - 2 * h[fa] + 1)
		return y + 1;
	if(k > h[x] - h[fa])
	{
		k -= h[x] - h[fa];
		k = h[y] - h[fa] + 1 - k + 1;
		swap(x, y);
	}
	k--;
	for(int i = maxl - 1; i >= 0; i--)
	{
		if(pw[i] <= k)
		{
			k -= pw[i];
			x = par[x][i];
		}
	}
	return x + 1;
}


int main()
{
	cin >> t;
	while(t)
	{
		t--;
		scanf("%d", &n);
		pre();
		for(int i = 0; i < n - 1; i++)
		{
			int x, y, w;
			scanf("%d %d %d", &x, &y, &w);
			x--;
			y--;
			adj[x].push_back(mp(y,w));
			adj[y].push_back(mp(x,w));
		}
		dfs(0);
		cin >> s;
		int st, e, k;
		while(s != "DONE")
		{
			if(s == "DIST")
			{
				scanf("%d %d", &st, &e);
				st--;
				e--;
				if(e == st)
					printf("%d\n", 0);
				else
				{
					int fa = lca(st, e);
					cout << ((long long)dis[st] + dis[e] - 2 * dis[fa]) << endl;
				}
			}
			else
			{
				scanf("%d %d %d", &st, &e, &k);
				st--;
				e--;
				printf("%d\n", kth(st, e, k));
			}
			cin >> s;
		}
		printf("\n");
	}

}
