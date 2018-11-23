#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair

using namespace std;

const int maxn = 1000 * 500 + 1000;
typedef pair<int, int> pie;
vector<int> adj[maxn];
bool seen[maxn];
int h[maxn];
int n;
vector<int> vert;

void dfs(int v)
{
	seen[v] = true;
	if(adj[v].size() == 1 && v != 0)
		vert.push_back(h[v]);
	for(auto u : adj[v])
		if(!seen[u])
		{
			h[u] = h[v] + 1;
			dfs(u);
		}
}

int findans()
{
	int a = 0;
	sort(vert.begin(), vert.end());
	for(int i = 0; i < vert.size(); i++)
		a = max(a + 1, vert[i]);
	return a;

}
int main()
{
	cin >> n;
	for(int i = 0,x ,y; i < n - 1; i++)
	{
		scanf("%d %d", &x, &y);
		x--;
		y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	seen[0] = true;
	int ans = 0;
	for(auto v : adj[0])
	{
		h[v] = 1;
		vert.clear();
		dfs(v);
		ans = max(findans(), ans);
	}
	cout << ans << endl;

}
