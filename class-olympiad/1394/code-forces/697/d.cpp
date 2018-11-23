#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;
const int maxn = 1e5 + 1000;
int par[maxn], sz[maxn];
long double ans[maxn];
bool seen[maxn];
vector<int> adj[maxn];
int n;

int dfs(int v)
{
	sz[v] = 1;
	seen[v] = true;
	for(auto u : adj[v])
	{
		if(!seen[u])
		{
			par[u] = v;
			sz[v] += dfs(u);
		}
	}
	return sz[v];
}

void getans(int v)
{
	if(v == 0)
		ans[v] = 1;
	else
	{
		seen[v] = true;
		int p = par[v];
		ans[v] = (double)(sz[p] - sz[v] - 1) / 2.00 + ans[p] + (double)1;
	}
	for(auto u : adj[v])
		if(!seen[u])
			getans(u);
}


int main()
{
	cin >> n;
	for(int i = 1, temp; i < n; i++)
	{
		cin >> temp;
		temp--;
		adj[temp].push_back(i);
	}
	dfs(0);
	memset(seen, 0, sizeof seen);
	getans(0);
	cout.precision(1);
	cout << fixed;
	for(int i = 0; i < n; i++)
		cout << ans[i] << " ";
	cout << endl;
}	
