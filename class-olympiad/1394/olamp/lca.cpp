/*
 * =====================================================================================
 *
 *       Filename:  lca.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  ۱۶/۰۱/۱۶ ۱۶:۵۴:۰۵
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <bits/stdc++.h>


using namespace std;

const int maxn = 1000 * 100;
const int maxl = 20;
long long pw[maxl], lg[maxn + 100];
int n, q;
vector<int> adj[maxn + 100];
int par[maxn + 100][maxl];
bool seen[maxn + 100];
int h[maxn + 100];
void dfs(int);

void pre()
{
	pw[0] = 1;
	for(int i = 1; i < maxl; i++)
		pw[i] = pw[i - 1] * 2;
	lg[1] = 0;
	for(int i = 2; i <= n; i++)
		lg[i] = lg[i / 2] + 1;
	dfs(0);
}

void dfs(int v)
{
	seen[v] = true;
	for(int i = 1; i < maxl; i++)
		par[v][i] = par[par[v][i - 1]][i - 1];
	for(int i = 0; i < adj[v].size(); i++)
	{
		int u = adj[v][i];
		if(!seen[u])
		{
			h[u] = h[v] + 1;
			par[u][0] = v;
			dfs(u);
		}
	}
}

int lca(int v, int u)
{
	if(h[v] < h[u])
		swap(u, v);
	for(int i = maxl - 1; i >= 0; i--)
		if(h[par[v][i]] >= h[u])
			v = par[v][i];
	for(int i = maxl - 1; i >= 0; i--)
		if(par[u][i] != par[v][i])
		{
			v = par[v][i];
			u = par[u][i];
		}
	return par[u][0];
}


int main()
{
	cin >> n >> q;
	for(int i = 0; i < n - 1; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		x--;
		y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	pre();
	for(int i = 0; i < q; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		cout << lca(u - 1, v - 1) + 1 << endl;
	}
	return 0;
}
