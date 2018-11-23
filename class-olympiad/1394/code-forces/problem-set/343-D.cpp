#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair

using namespace std;

typedef pair<int, int> pie;
const int maxn = 500 * 1000 + 100;
int seg[2][4*maxn];
int n, q;
vector<int> adj[maxn];
bool seen[maxn];
int cnt = 0;
int st[maxn], fi[maxn];

void dfs(int v, int par = -1)
{
	st[v] = cnt++;
	for(auto u : adj[v])
		if(u != par)
			dfs(u, v);
	fi[v] = cnt;
}

void upone(int s, int e, int x, int l, int r, int t)
{
	if(r <= s || e <= l)
		return;
	if(l <= s && e <= r)
	{
		seg[0][x] = t;
		return;
	}
	int mid = (s+e)/2;
	upone(s, mid, 2*x, l, r, t), upone(mid, e, 2*x + 1, l, r, t);
}

void uptwo(int s, int e, int x, int v, int t)
{
	seg[1][x] = t;
	if(e - s < 2)
		return;
	int mid = (s+e)/2;
	if(v < mid)
		uptwo(s, mid, 2*x, v, t);
	else
		uptwo(mid, e, 2*x + 1, v, t);

}

int getone(int s, int e, int x, int v)
{
	if(e - s < 2)
		return seg[0][x];
	int mid = (s+e)/2;
	if(v < mid)
		return max(seg[0][x], getone(s, mid, 2*x, v));
	else
		return max(seg[0][x], getone(mid, e, 2*x + 1, v));
}

int gettwo(int s, int e, int x, int l, int r)
{
	if(r <= s || e <= l)
		return -1;
	if(l <= s && e <= r)
		return seg[1][x];
	int mid = (s+e)/2;
	return max(gettwo(s, mid, 2*x, l, r), gettwo(mid, e, 2*x + 1, l , r));
}




int main()
{
	scanf("%d", &n);
	for(int i = 0,x ,y; i < n - 1; i++)
	{
		scanf("%d %d", &x , &y);
		x--;
		y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(0);
	memset(seg, -1, sizeof seg);
	scanf("%d", &q);
	for(int i = 0, c, v; i < q; i++)
	{
		scanf("%d %d", &c, &v);
		v--;
		if(c == 1)
			upone(0, n, 1, st[v], fi[v], i + 1);
		else if(c == 2)
			uptwo(0, n , 1, st[v], i + 1);
		else
		{
			int t1 = getone(0, n, 1, st[v]);
			int t2 = gettwo(0, n, 1, st[v], fi[v]);
			printf("%d\n", t1 > t2);

		}
	}
}
