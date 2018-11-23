/*
 * =====================================================================================
 *
 *       Filename:  kruskal.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  ۱۵/۱۱/۲۷ ۱۶:۴۵:۰۲
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



struct edge
{
	int x, y, w;
	edge()
	{

	}
	edge(int i, int j, int c)
	{
		x = i;
		y = j;
		w = c;
	}
};


bool operator < (const edge & a,const edge & b)
{
	return a.w < b.w;
}


const int maxn = 1000 * 1000 + 1000;
edge adj[maxn];
int par[maxn];
int siz[maxn];
vector<edge> mst;
int n ,m;

void pre()
{
	for(int i = 0; i < n; i++)
	{
		siz[i] = 1;
		par[i] = i;
	}
}
int fpar(int v)
{
	if(par[v] == par[par[v]])
		return par[v];
	return par[v] = fpar(par[v]);
}
void merge(int u, int v)
{
	u = fpar(u);
	v = fpar(v);
	if(u == v)
		return;
	if(siz[u] > siz[v])
		swap(u, v);
	siz[v] += siz[u];
	cerr << " merge  " << u << ":" <<  par[u] << "  " << v << endl;
	par[u] = v;
}




void kruskal()
{
	for(int i = 0; i < m; i++)
	{
		int x, y;
		x = adj[i].x;
		y = adj[i].y;
		if(fpar(y) != fpar(x))
		{
			cerr << x << ":" << fpar(x) << "   " << y << ":" << fpar(y) << endl;
			merge(x, y);

			mst.push_back(adj[i]);
		}
	}
}


int main()
{
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int x, y, w;
		scanf("%d %d %d", &x, &y, &w);
		x--;
		y--;
		adj[i] = edge(x, y, w);
	}
	pre();
	sort(adj, adj + m);
	kruskal();
	cout << mst.size() << endl;
	for(int i = 0; i < mst.size(); i++)
		cout << mst[i].x + 1  << "  " << mst[i].y + 1 << endl;
	return 0;
}
