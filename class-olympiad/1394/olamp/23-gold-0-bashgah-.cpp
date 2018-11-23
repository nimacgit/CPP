/*
 * =====================================================================================
 *
 *       Filename:  bashgah.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  ۱۶/۰۲/۰۷ ۱۲:۲۰:۰۴
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair

using namespace std;
const int maxn =100 * 1000 + 100;
int n, m;
const int maxnn = 5000;
const int inf = 1e9;
typedef pair<int, int> pie;

struct graph
{
	int n;
	vector<int> adj[maxnn];
	vector<int> tadj[maxnn];
	bool seen[maxnn];
	vector <int> top;
	graph(int sz = 0)
	{
		n = sz;
	}
	void addedge(int v, int u)
	{
		adj[v].push_back(u);
		tadj[u].push_back(v);
	}
	void dfs(int v, vector <int> *adj)
	{
		seen[v] = true;
		for(auto u : adj[v])
			if(!seen[u])
				dfs(u, adj);
		top.push_back(v);
	}

	vector<int> scc()
	{
		for(int i = 0; i < n; i++)
			if(!seen[i])
				dfs(i, adj);
		memset(seen, 0, sizeof seen);
		vector<int> ord = top;
		vector<int> comp(n);
		int cnt = 1;
		reverse(ord.begin(), ord.end());
		for(auto u : ord)
		{
			top.clear();
			if(!seen[u])
			{
				dfs(u, tadj);
				for(auto l : top)
					comp[l] = cnt;
				cnt++;
			}
		}
		return comp;
	}
	void clear()
	{
		for(int i = 0; i < n; i++)
			adj[i].resize(0), tadj[i].resize(0);
		top.resize(0);
		memset(seen, 0, sizeof seen);
	}
};

struct twosat
{
	graph g;
	int n;
	vector<pie> clause;
	twosat(int sz)
	{	
		n = sz;
		g = graph(2 * n);
	}

	void addclause(int v, int u)
	{
		g.addedge(v ^ 1, u), g.addedge(u ^ 1, v);
	}
	void clear()
	{
		g.clear();
		clause.resize(0);
	}
	bool solve()
	{
		vector<int> ans;
		ans = g.scc();
		for(int i = 0; i < n; i++)
			if(ans[2 * i] == ans[2 * i + 1])
				return false;
		return true;
	}
};


pair<int, pie> points[maxnn];




bool check(int dis)
{
	twosat solver(n);
	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(abs(points[i].S.F - points[j].S.F)
					+ abs(points[i].S.S - points[j].S.S) < dis)
				solver.addclause(2 * i, 2 * j);
			if(points[i].F == points[j].F)
				solver.addclause(2 * i + 1, 2 * j + 1);
		}
	}
	return solver.solve();
}


int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
	{
		int x, y, c;
		scanf("%d %d %d", &x, &y, &c);
		points[i] = mp(c, mp(x, y));
	}
	sort(points, points + n);
	int s = 0, e = inf;
	while(e - s > 1)
	{
		int mid = (s+e) / 2;
		if(check(mid))
			s = mid;
		else
			e = mid;
	}
	printf("%d\n", s);

}
