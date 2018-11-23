#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

const int maxn = 1000 * 300;
bool un[maxn];
vector<int> adj[maxn];
int n, k;
long long ans = 0;
int sz[maxn];

void dfs(int v, int p)
{
	for(auto u : adj[v])
	{
		if(u != p)
		{
			dfs(u, v);
			ans += min(2 * k - sz[u], sz[u]);
			sz[v] += sz[u];
		}
	}
	if(un[v])
		sz[v]++;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for(int i = 0, temp; i < 2* k; i++)
	{
		cin >> temp;
		temp--;
		un[temp] = true;
	}
	for(int i = 0, x, y; i < n - 1; i++)
	{
		cin >> x >> y;
		x--;
		y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(0, -1);
	cout << ans << endl;
	
	
}
