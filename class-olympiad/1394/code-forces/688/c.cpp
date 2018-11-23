#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;


const int maxn = 1000 * 100 + 1000;
vector<int> adj[maxn];
int n, m;
int h[maxn];
vector<int> z, f;
bool seen[maxn];

bool dfs(int v)
{
	bool ans = true;
	for(int i = 0; i < adj[v].size(); i++)
	{
		int u = adj[v][i];
		if(!seen[u])
		{
			seen[u] = true;
			h[u] = h[v] + 1;
			ans = ans & dfs(u);
		}
		else
			if((h[u] - h[v]) % 2 == 0)
				return false;
	}
	if(h[v] % 2 == 0)
		z.push_back(v);
	else
		f.push_back(v);
	return ans;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	int x, y;
	for(int i = 0; i < m; i++)
	{
		cin >> x >> y;
		x--;
		y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	bool ans = true;
	for(int i = 0; i < n; i++)
	{
		if(!seen[i])
		{
			h[i] = 0;
			seen[i] = true;
			ans &= dfs(i);
		}
	}
	if(ans)
	{
		cout << z.size() << endl;
		for(int i : z)
			cout << i + 1 << " ";
		cout << endl;
		cout << f.size() << endl;
		for(int i : f)
			cout << i + 1 << " ";
		cout << endl;
	}
	else
		cout << -1 << endl;
}
