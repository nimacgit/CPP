#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <list>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <bits/stdc++.h>


using namespace std;

const int maxn = 1000;


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

};


typedef pair<int, int> pie;
pie a[maxn];
int rev[maxn];




int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0, x; i < n; i++)
	{
		cin >> x;
		a[i] = make_pair(x, i);
	}
	sort(a, a + n, greater<pie>());
	for(int i = 0; i < n; i++)
		rev[a[i].second] = i;
	bipartite *g = new bipartite(n, n);
	for(int i = 0, m; i < n; i++)
	{
		cin >> m;
		for(int j = 0, k; j < m; j++)
		{
			cin >> k;
			k--;
			g->addedge(rev[i], k);
		}
	}
	g->matching();
	for(int i = 0; i < n; i++)
		cout << g->match[0][rev[i]] + 1 << " ";
	cout << endl;




	
}
