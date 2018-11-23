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
const int maxn = 1000;
vector <int> adj[maxn + 100];
bool seen[maxn + 100];
int h[maxn + 100];
int n, m;
vector <int> myque;
const int INF = 1e9;
int par[maxn + 100];

void pre()
{
	fill(seen, seen + n, false);
	myque.clear();
	fill(par, par + n, false);
}


int bfs(int s)
{
	pre();
	myque.push_back(s);
	seen[s] = true;
	h[s] = 0;
	for(int i = 0; i < myque.size(); i++)
	{
		int v= myque[i];
		for(int j = 0; j < adj[v].size(); j++)
		{
			int u = adj[v][j];
			if(seen[u] && par[v] != u)
				return h[u] + h[v] + 1;
			myque.push_back(u);
			h[u] = h[v] + 1;
			par[u] = v;
			seen[u] = true;
		}
	}
	return INF;
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
		adj[y].push_back(x);
	}
	int w = INF;
	for(int i = 0; i < n; i++)
		w = min(w, bfs(i));
	if(w == INF)
		cout << -1 << endl;
	cout << w << endl;
}
