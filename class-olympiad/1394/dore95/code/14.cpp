#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second
#define pb push_back
using namespace std;

typedef pair<int, int> pie;
const int maxn = 1e5 + 10;
int n, m;
vector<int> adj[maxn];
vector<int> bor;
bool seen[maxn];
int low[maxn], h[maxn], par[maxn];
int root;
void dfs(int v)
{
	seen[v] = true;
	low[v] = h[v];
	int co = 0;
	bool flag = false;
	for(auto u : adj[v])
	{
		if(u != par[v])
		{
			if(!seen[u])
			{
				par[u] = v;
				h[u] = h[v] + 1;
				dfs(u);
				co++;
				if(low[u] >= h[v])
					flag = true;
				low[v] = min(low[v], low[u]);
			}
			else
				low[v] = min(low[v], h[u]);
		}
	}
	if((flag && v!=root) || (v==root && co > 1))
		bor.pb(v);
}





int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0,x , y; i < m; i++)
	{
		cin >> x >> y;
		x--;
		y--;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	for(int i = 0; i < n; i++)
	{
		if(!seen[i])
		{
			root = i;
			dfs(i);
		}
	}
	sort(bor.begin(), bor.end());
	cout << bor.size() << endl;
	for(int i = 0; i < bor.size(); i++)
		cout << bor[i] + 1 << " ";
	if(!bor.empty())
		cout << endl;
}
