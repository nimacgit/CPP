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
const int maxn = 10 * 1000;
typedef pair<int,int> pie;
int n, m, k;

struct graph
{
	int n;
	vector<int> adj[maxn];
	vector<int> tadj[maxn];
	bool seen[maxn];
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




int main()
{
	scanf("%d %d %d", &n, &m, &k);
	twosat ans(4000);
	for(int i = 0; i < k; i++)
	{
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		if(y1 == y2)
		{
			if(x1 < x2)
				ans.addclause(2 * y1, 2 * y1);
			else
				ans.addclause(2 * y1 + 1, 2 * y1 + 1);
		}
		else if(x1 == x2)
		{
			if(y1 < y2)
				ans.addclause(2 * x1 + 2 * 1000, 2 * x1 + 2 * 1000);
			else
				ans.addclause(2 * x1 + 1 + 2 * 1000, 2 * x1 + 1 + 2 * 1000);
		}
		else 
		{
			int x3 = 2 * (x1 + 1000), x4 = 2 * (x2 + 1000), y3 = 2 * y1, y4 = 2 * y2;
			if(y1 > y2)
			{
				x3++;
				x4++;
			}
			if(x1 > x2)
			{
				y3++;
				y4++;
			}
			ans.addclause(x3, x4);
			ans.addclause(x3, y3);
			ans.addclause(y4, x4);
			ans.addclause(y4, y3);
		}

	}
	printf("%s\n", (ans.solve() ? "Yes" : "No"));


}
