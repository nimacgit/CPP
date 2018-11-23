#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;
const int maxn = 1e5 + 100, maxl = 20;
int par[maxn][maxl];
int h[maxn];
bool seen[maxn];
vector<int> adj[maxn];
int n, m;
int val[maxn];
int ans[maxn];
pie edge[maxn];

int lca(int v, int u)
{
	if(h[v] > h[u])
		swap(v, u);
	for(int i = maxl - 1; i >= 0; i--)
		if(h[par[u][i]] >= h[v])
			u = par[u][i];
	if(u == v)
		return v;
	for(int i = maxl - 1; i >= 0; i--)
		if(par[u][i] != par[v][i])
		{
			u = par[u][i];
			v = par[v][i];
		}
	return par[v][0];
}

void dfs(int v)
{
	seen[v] = true;
	for(auto u : adj[v])
	{
		if(!seen[u])
		{
			h[u] = h[v] + 1;
			par[u][0] = v;
			for(int i = 1; i < maxl; i++)
				par[u][i] = par[par[u][i - 1]][i - 1];
			dfs(u);
		}
	}
}

void sfd(int v)
{
	seen[v] = true;
	ans[v] = 0;
	for(auto u : adj[v])
	{
		if(!seen[u])
		{
			sfd(u);
			ans[v] += ans[u];
			ans[v] += val[u];
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0, x, y; i < n - 1; i++)
	{
		cin >> x >> y;
		x--, y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
		edge[i] = mp(x, y);
	}
	for(int i = 0; i < n; i++)
		if(!seen[i])
		{
			for(int j = 0; j < maxl; j++)
				par[i][j] = i;
			dfs(i);
		}
	cin >> m;
	for(int i = 0, x, y; i < m; i++)
	{
		cin >> x >> y;
		x--, y--;
		int l = lca(x, y);
		val[l] -= 2;
		val[y]++, val[x]++;
	}
	memset(seen, 0, sizeof seen);
	for(int i = 0; i < n; i++)
	{
		if(!seen[i])
			sfd(i);
	}
	for(int i = 0; i < n - 1; i++)
	{
		int x = edge[i].F, y = edge[i].S;
		if(h[x] < h[y])
			cout << ans[y]+val[y] << " ";
		else
			cout << ans[x]+val[x] << " ";
	}
	cout << endl;
}
