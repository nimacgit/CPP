/*
 * =====================================================================================
 *
 *       Filename:  dijkstra.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  ۱۵/۱۱/۱۳ ۱۵:۴۷:۵۳
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <bits/stdc++.h>
#define mp make_pair

using namespace std;

typedef pair<int, int> pie;
const int maxn = 1000 * 10 + 100;
const int inf = 1000 * 1000 * 100;
vector<pair <int, int> > adj[maxn];
int n, m;
bool seen[maxn];
int dis[maxn];
set < pair<int, int> > myset;



void dijkstra(int s, int t)
{
	for(int i = 0; i < n; i++)
		dis[i] = inf;
	dis[s] = 0;
	for(int i = 0; i < n; i++)
	{
		int mini = 0;
		for(int i = 1; i < n; i++)
		{
			if(!seen[i] && dis[i] < dis[mini])
				mini = i;
		}
		seen[mini] = true;
		for(int j = 0; j < adj[mini].size(); j++)
		{
			int u = adj[mini][j].first;
			int c = adj[mini][j].second;
			d[u] = min(d[mini] + c, d[u]);
		}

	}
}

void pre(int s)
{
	for(int i = 0; i < n; i++)
		dis[i] = inf;
	dis[s] = 0;
	for(int i = 0; i < n; i++)
		myset.insert(mp(dis[i], i));
}


void dijkstra2(int s, int t)
{
	pre(s);
	for(int i = 0; i < n; i++)
	{
		pie mini = *myset.begin();
		myset.erase(myset.begin());
		int u = mini.second;
		for(int j = 0; j < adj[u].size(); j++)
		{
			int v = adj[u][j].first;
			int c = adj[u][j].second;
			if(dis[v] > dis[u] + c)
			{
				myset.erase(mp(dis[v], v));
				dis[v] = dis[u] + c;
				myset.insert(mp(dis[v], v));
			}
		}
	}
}




int main()
{
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int x, y, c;
		cin >> x >> y >> c;
		x--;
		y--;
		adj[x].push_back(mp(y, c));
		adj[y].push_back(mp(x, c));
	}

}
