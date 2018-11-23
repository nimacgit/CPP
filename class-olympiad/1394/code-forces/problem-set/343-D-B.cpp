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
const int maxn = 500 * 1000 + 100;
vector<int> adj[maxn];
bool seen[maxn];
int sz[maxn];
int cnt = 0;
int pos[maxn];
pie seg[4*maxn];


int dfs(int v)
{
	pos[v] = cnt++;
	int s = 0;
	seen[v] = true;
	for(auto u : adj[v])
		if(!seen[u])
			s+=dfs(u) + 1;
	return sz[v] = s;
}

void upone(int s, int e, int start, int end, int t, int segnum)
{
	if(s >= start && e <= end)
	{
		seg[segnum].F = t;
		return;
	}
	if(s > end || e < start)
		return;
	if(s == e)
		return;
	int mid = (s+e)/2;
	if(mid + 1 > end)
		upone(s, mid, start, end, t, 2*segnum);
	else
	{
		if(mid < start)
			upone(mid + 1, e, start, end, t, 2*segnum + 1);
		else
			upone(s,mid, start,mid, t, 2*segnum), upone(mid + 1, e, mid + 1, end, t, 2*segnum + 1);
	}
}

void uptwo(int s, int e, int v, int t, int segnum)
{
	if(s <= v && e >= v)
	{
		seg[segnum].S = t;
		if(s == e)
			return;
		int mid = (s+e)/2;
		if(v <= mid)
			uptwo(s, mid, v, t, 2*segnum);
		else
			uptwo(mid + 1, e, v, t, 2*segnum + 1);	
	}
}

int getone(int s, int e, int v, int segnum)
{
	if(s > v || e < v)
		return -1;
	if(s == e)
		return seg[segnum].F;
	int mid = (s+e)/2;
	if(v <= mid)
		return max(getone(s, mid, v, 2*segnum), seg[segnum].F);
	return max(getone(mid + 1, e, v, 2*segnum + 1), seg[segnum].F);
}

int gettwo(int s, int e, int start, int end, int segnum)
{
	if(e < start || s > end)
		return 0;
	if(s == e)
		return seg[segnum].S;
	int mid = (s+e)/2;
	if(s >= start && e <= end)
		return max(seg[segnum].S, max(gettwo(s, mid, start, end, 2*segnum), gettwo(mid + 1, e, start, end, 2*segnum + 1)));
	return max(gettwo(s,mid, start, end, 2*segnum), gettwo(mid + 1, e, start, end, 2*segnum + 1));
}








int main()
{
	int n, q;
	scanf("%d", &n);
	for(int i = 0, x, y; i < n - 1; i++)
	{
		scanf("%d %d", &x, &y);
		x--;
		y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(0);
	for(int i = 0; i < 2 * n; i++)
		seg[i].F = -1;
	scanf("%d", &q);
	for(int i = 0; i < q; i++)
	{
		int c, v;
		scanf("%d %d", &c , &v);
		v--;
		if(c == 1)
			upone(1, n, pos[v] + 1, pos[v] + 1 + sz[v], i+1, 1);
		else if(c == 2)
			uptwo(1, n, pos[v] + 1, i + 1, 1);
		else
		{
			int t1 = getone(1, n, pos[v] + 1, 1), t2 = gettwo(1, n, pos[v] + 1, pos[v] + 1 + sz[v], 1);
			if(t1 > t2)
				printf("1\n");
			else
				printf("0\n");
		}

		

	}
}
