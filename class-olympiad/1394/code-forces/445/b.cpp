#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

const int maxn = 100;
vector<int> adj[maxn];
int n, m;
bool seen[maxn];
void dfs(int v)
{
	for(auto u : adj[v])
	{
		if(!seen[u])
		{
			seen[u] = true;
			dfs(u);
		}
	}
}

int main()
{
	long long ans = 1, two = 0;
	cin >> n >> m;
	for(int i = 0, x, y; i < m; i++)
	{
		cin >> x >> y;
		x--;
		y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(int i = 0; i < n; i++)
	{
		if(!seen[i])
		{
			seen[i] = true;
			dfs(i);
			two++;
		}
	}
	two = n - two;
	for(int i = 1; i <= two; i++)
		ans *= 2;
	cout << ans << endl;
}
