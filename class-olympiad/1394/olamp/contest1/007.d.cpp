#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair

using namespace std;

typedef pair<int, int> pie;

const int maxn = 1000 * 1000;
vector<int> adj[maxn + 100];
bool mark[maxn + 100];
int h[maxn + 100];
int n , m;


int dfs(int v)
{
	int maxi = h[v];
	mark[v] = true;
	for(int i = 0; i < adj[v].size(); i++)
	{
		int u = adj[v][i];
		if(!mark[u])
		{
			maxi = max(dfs(u), maxi);
		}
		h[v] = max(h[v], h[u] + 1);
	}
	return max(h[v], maxi);
	
}




int main()
{
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		x--;
		y--;
		adj[x].push_back(y);
	}
	int maxim = 0;
	for(int i = 0; i < n; i++)
	{
		if(!mark[i])
			maxim = max(dfs(i), maxim);
	}
	cout << maxim + 1 << endl;
}
