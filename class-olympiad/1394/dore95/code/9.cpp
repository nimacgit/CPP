#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

bool adj[maxn][maxn];
int dis[maxn][maxn];
vector<int> mv;
bool bfs(int v)
{
	mv.claer();
	mv.push_back(v);
	seen[v] = true;
	for(int i = 0; i < mv.size(); i++)
	{
		v = mv[i];
		for(int j = 0; j < n; j++)
		{
			if(j != v)
		}
	}
}


bool isok(int d)
{
	
	for(int i = 0; i < n; i++)
	{
		seen[i] = false;
		for(int j = 0; j < n; j++)
		{
			if(dis[i][j] < d)
				adj[i][j] = 1;
			else
				adj[i][j] = 0;
		}

	}
	for(int i = 0; i < n; i++)
		if(!seen[i])
			if(!bfs(i))
				return false;
	return true;
}


int main()
{
	cin >> n;
	for(int i = 0, x, y; i < n; i++)
	{
		cin >> x >> y;
		p[i] = mp(x, y);
	}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			dis[i][j] = abs(p[i].F - p[j].F) + abs(p[i].S - p[j].S);
	int s = 0, e = 1e7;
	while(s != e)
	{
		int mid = (s+e)/2;
		if(isok(mid))
			s = mid;
		else
			e = mid - 1;
	}
	cout << s << endl;

}
