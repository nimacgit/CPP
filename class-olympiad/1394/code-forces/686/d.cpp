#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;
const int maxn = 4e5;
int ans[maxn];
int sz[maxn];
int par[maxn];
vector<int> adj[maxn];
int n, q;

void dfs(int v)
{
	sz[v] = 1;
	if(adj[v].size() == 0)
	{
		ans[v] = v;
		return ;
	}
	for(auto u : adj[v])
	{
		dfs(u);
		sz[v]+=sz[u];
	}
	for(auto u : adj[v])
	{
		int o = ans[u];
		while(o != v)
		{
			bool flag = false;
			for(auto l : adj[u])
				if(sz[l] > (sz[v] / 2))
					flag = true;
			if(!flag && !((sz[v] - sz[o]) > sz[v]/2))
			{
				ans[v] = o;
				return;
			}
			o =  par[o];
		}
	}
	ans[v] = v;
}

int main()
{
	cin >> n >> q;
	for(int i = 1, temp; i < n; i++)
	{
		cin >> temp;
		temp--;
		adj[temp].push_back(i);
		par[i] = temp;
	}
	dfs(0);
	for(int i = 0, temp; i < q; i++)
	{
		cin >> temp;
		temp--;
		cout << ans[temp]+1 << endl;
	}

}
