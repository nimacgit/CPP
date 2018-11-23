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
const int maxn = 50 * 1000 + 100;







struct bipartite
{

	vector<int> adj[maxn];
	bool seen[maxn];
	int match[2][maxn];
	int n, m;
	bipartite(int tn, int tm)
	{
		n = tn;
		m = tm;
		memset(match, -1, sizeof match);
		memset(seen, 0, sizeof seen);
	}
	void addedge(int x, int y)
	{
		adj[x].push_back(y);
	}
	bool aug(int v)
	{
		if(seen[v])
			return false;
		seen[v] = true;
		for(int j = 0; j < (int)adj[v].size(); j++)
		{
			int u = adj[v][j];
			if(match[1][u] == -1 || aug(match[1][u]))
				return match[1][u] = v, match[0][v] = u, true;
		}
		return false;

	}

	int matching()
	{
		int cnt = 0;
		for(int i = 0; i < n; i++)
		{
			cnt += aug(i);
			memset(seen, 0, sizeof seen);
		}
		return cnt;
	}
	int fastmatching()
	{
		int cnt = 0;
		bool found = true;
		while(found)
		{
			memset(seen, 0, sizeof seen);
			found = false;
			for(int i = 0; i < n; i++)
				if(match[0][i] == -1)
					found |= (aug(i) ? (cnt++, true) : false);
		}
		return cnt;
	}


};


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, p;
	cin >> n >> m >> p;
	bipartite *g = new bipartite(n ,m);
	for(int i = 0, x, y; i < p; i++)
	{
		cin >> x >> y;
		x--;
		y--;
		g->addedge(x, y);
	}
	cout << g->fastmatching() << endl;

}

