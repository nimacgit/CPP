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
const int maxn = 1000 * 100 + 100;
int n;
int c[maxn];
int cnt = 0;
vector<int> adj[maxn];
map<int, int> col[maxn];
int ans[maxn];
bool seen[maxn];
map<int, int>::iterator it, bit;
void dfs(int v)
{
	seen[v] = true;
	if(adj[v].size() == 1 && v != 0)
	{
		col[v].insert(mp(c[v], 1));
		ans[v] = c[v];
		return;
	}
	col[v][c[v]] = 1;
	for(auto u : adj[v])
		if(!seen[u])
		{
			dfs(u);
			while(!col[u].empty())
			{
				col[v][(col[u].begin())->F] += col[u].begin()->S;
				col[u].erase(col[u].begin());
			}
		}
	it = col[v].end();
	it--;
	bit = it;
	ans[v] = it->F;
	it--;
	while(it->S == (bit)->S && bit != col[v].begin())
	{
		it--;
		bit--;
		ans[v]+=it->F;
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0 ; i < n; i++)
		cin >> c[i];
	for(int i = 0, x, y; i < n - 1; i++)
	{
		cin >> x >> y;
		x--;
		y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(0);
	for(int i = 0; i < n; i++)
		cout << ans[i] << " ";
	cout << endl;
}
