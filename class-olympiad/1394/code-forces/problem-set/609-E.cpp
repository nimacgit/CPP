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
const int maxn = 200 * 1000 + 100;
const int maxl = 20;
int lg[maxn];
int pw[maxl];
int bestedg[maxn][maxl];
vector<pie> adj[maxn];
int h[maxn];
struct yal
{
	int s, e, w, ind;

};
yal edg[maxn];
int par[maxn];
bool seen[maxn];
int parent[maxn][maxl];
long long ans[maxn];
long long mst;
int n, m;
int tpar[maxn];
void dfs(int);

bool comp(yal a, yal b){return a.w < b.w;}

void pre()
{
	for(int i = 0; i < n; i++)
	{
		par[i] = i;
		seen[i] = false;
		adj[i].clear();
		tpar[i] = i;
	}
}

void prelca()
{
	pw[0] = 1;
	lg[1] = 0;
	for(int i = 1; i < maxl; i++)
		pw[i] = pw[i - 1]*2;
	for(int i = 2; i < maxn; i++)
		lg[i] = lg[i / 2] + 1;
	bestedg[0][0] = 0;
	dfs(0);
}

int findpar(int u)
{
	if(u == par[u])
		return u;
	return par[u] = findpar(par[u]);
}

void dfs(int v)
{
	seen[v] = true;
	for(int i = 1; i < maxl; i++)
	{
		parent[v][i] = parent[parent[v][i - 1]][i - 1];
		bestedg[v][i] = max(bestedg[v][i - 1], bestedg[parent[v][i - 1]][i - 1]);
	}
	for(int i = 0; i < adj[v].size(); i++)
	{
		int u = adj[v][i].F;
		if(!seen[u])
		{
			h[u] = h[v] + 1;
			bestedg[u][0] = adj[v][i].S;
			parent[u][0] = v;
			dfs(u);
		}
	}
}


int lca(int v, int u)
{
	if(h[v] > h[u])
		swap(v, u);
	for(int i = maxl - 1; i >= 0; i--)
		if(h[parent[u][i]] >= h[v])
			u = parent[u][i];
	if(u == v)
		return v;
	for(int i = maxl - 1; i >= 0; i--)
		if(parent[u][i] != parent[v][i])
		{
			v= parent[v][i];
			u= parent[u][i];
		}
	return parent[v][0];
}

long long findans(int x, int y, int w)
{
	int fa = lca(x, y);
	int deltax = h[x] - h[fa], deltay = h[y] - h[fa];
	long long sum = mst + (long long)w;
	int fmax = 0;
	if(deltax > 0)
	{
		for(int i = lg[deltax]; i >= 0; i--)
			if(h[parent[x][i]] >= h[fa])
			{
				fmax = max(fmax, bestedg[x][i]);
				x = parent[x][i];
			}
	}
	if(deltay > 0)
		for(int i = lg[deltay]; i >= 0; i--)
			if(h[parent[y][i]] >= h[fa])
			{
				fmax = max(fmax, bestedg[y][i]);
				y = parent[y][i];
			}
	return sum -= (long long)fmax;
}

void rin()
{
	for(int i = 0; i < m; i++)
	{
		int x, y, w;
		scanf("%d %d %d", &x, &y, &w);
		x--;
		y--;
		edg[i].s = x;
		edg[i].e = y;
		edg[i].w = w;
		edg[i].ind = i;
	}
	pre();

}


void prime()
{
	sort(edg, edg + m, comp);
	for(int i = 0; i < m; i++)
	{
		int u = edg[i].e, v = edg[i].s;
		int fu = findpar(u), fv = findpar(v);
		if(fu != fv)
		{
			par[fu] = fv;
			mst += (long long)edg[i].w;
			adj[u].push_back(mp(v, edg[i].w));
			adj[v].push_back(mp(u, edg[i].w));
		}
	}
	prelca();

}

void gen()
{
	n = rand() % 100000;
	m = rand() % 200000;
	int j = 0;
	int k = 1;
	for(int i = 0; i < m; i++)
	{
		if(k == n)
		{
			k = j + 2;
			j++;
		}
		int w = rand() % 100000000;
		edg[i].s = j;
		edg[i].e = k;
		edg[i].ind = i;
		if(w % 2 == 1)
			edg[i].w = w;
		else
			edg[i].w = edg[rand() % (i + 1)].w;
		k++;
	}
	pre();
	
}

int tfpar(int u)
{
	if(u == tpar[u])
		return u;
	return tpar[u] = tfpar(tpar[u]);
}
void tpre()
{
	for(int i = 0; i < n; i++)
		tpar[i] = i;
}

long long tmst(int i)
{
	long long tsum = 0;
	par[edg[i].e] = edg[i].s;
	tsum += edg[i].w;
	for(int i = 0; i < m; i++)
	{
		int u = edg[i].e, v = edg[i].s;
		int fu = tfpar(u), fv = tfpar(v);
		if(fu != fv)
		{
			tpar[fu] = fv;
			tsum += (long long)edg[i].w;
		}
	}
	return tsum;

}

bool check()
{
	for(int i = 0; i < m; i++)
	{
		tpre();
		if(tmst(i) != ans[i])
			return false;
	}
	return true;
}

int main()
{
//	srand(time(NULL));
//	while(2)
//	{
		cin >> n >> m;
//		gen();
		rin();
		prime();
		for(int i = 0; i < m; i++)
			ans[edg[i].ind] = findans(edg[i].s, edg[i].e, edg[i].w);
		for(int i = 0; i < m; i++)
			cout <<  ans[i] << endl;
	/*  	if(check())
		{
			cerr << n << " " << m << endl;
			for(int i = 0; i < m; i++)
				cerr << edg[i].s << " " << edg[i].e << " " << edg[i].w << endl;
			return 0;
		}
		*/
	//}

}
