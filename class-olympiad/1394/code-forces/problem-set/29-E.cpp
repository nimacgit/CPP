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
const int maxn = 1000;
vector<int> adj[maxn];
bool seen[2][maxn][maxn];
bool can[2][maxn][maxn];
vector<pair<int, pie> > myvec;
pair<int, pie> par[2][maxn][maxn];
int n, m;


void bfs(int s, int e)
{
	seen[0][s][e] = true;
	myvec.push_back(mp(0,mp(s, e)));
	par[0][s][e] = mp(-1, mp(-1, -1));
	for(int i = 0; i < n; i++)
		seen[0][i][i] = true;
	for(int i = 0; i < myvec.size(); i++)
	{
		pair<int, pie> v = myvec[i];
		if(v.F == 0 && v.S.F == e && v.S.S == s)
			return;
		if(v.F == 0)
		{
			for(auto u : adj[v.S.F])
				if(!seen[1][u][v.S.S])
				{
					par[1][u][v.S.S] = mp(0, mp(v.S.F, v.S.S));
					seen[1][u][v.S.S] = true;
					myvec.push_back(mp(1, mp(u, v.S.S)));
				}
		}
		else
			for(auto u : adj[v.S.S])
				if(!seen[0][v.S.F][u])
				{
					par[0][v.S.F][u] = mp(1, mp(v.S.F, v.S.S));
					seen[0][v.S.F][u] = true;
					myvec.push_back(mp(0, mp(v.S.F, u)));
				}
	}

}



int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < n; j++)
			for(int l = 0; l < n; l++)
				par[i][j][l] = mp(-1, mp(-1, -1));
	for(int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		x--;
		y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	bfs(0, n - 1);
	if(par[0][n - 1][0].F == -1)
	{
		cout << -1 << endl;
		return 0;
	}
	int f = 0, i = n - 1, j = 0;
	vector<int> vert[2];
	while(par[f][i][j].F != -1)
	{
		if(f == 0)
			vert[1].push_back(j);
		else
			vert[0].push_back(i);
		auto v = par[f][i][j];
		i = v.S.F;
		j = v.S.S;
		f = f ^ 1;
	}
	vert[1].push_back(n - 1);
	vert[0].push_back(0);
	reverse(vert[0].begin(), vert[0].end());
	reverse(vert[1].begin(), vert[1].end());
	printf("%d\n", vert[0].size() - 1);
	for(int i = 0; i < vert[0].size(); i++)
		printf("%d ", vert[0][i] + 1);
	printf("\n");
	for(int i = 0; i < vert[1].size(); i++)
		printf("%d ", vert[1][i] + 1);
	printf("\n");



}

