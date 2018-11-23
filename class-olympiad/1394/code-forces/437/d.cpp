#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;


const int maxn = 1e5 + 1000;
long long par[maxn], sz[maxn];
vector<int> adj[maxn];
pie a[maxn];
long long inf = 1e5, n , m;
bool seen[maxn];

int getpar(int a)
{
	if(par[a] != a)
		return par[a] = getpar(par[a]);
	return a;
}

void mrg(int v, int u)
{
	u = getpar(u);
	v = getpar(v);
	if(u != v)
	{
		if(sz[u] > sz[v])
			swap(v, u);
		par[u] = v;
		sz[v] += sz[u];
	}
}


int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 0,temp; i < n; i++)
	{
		sz[i] = 1;
		par[i] = i;
		cin >> temp;
		a[i] = mp(temp, i);
	}
	sort(a, a + n);
	reverse(a, a + n);
	for(int i = 0, x, y; i < m; i++)
	{
		cin >> x >> y;
		x--;
		y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	long long ans = 0;
	for(int i = 0; i < n; i++)
	{
		long long v = a[i].S, c = a[i].F;
		seen[v] = true;
		for(auto u : adj[v])
			if(seen[u] && getpar(u) != getpar(v))
			{
				v = getpar(v);
				u = getpar(u);
				ans += sz[v] * sz[u] * c;
				mrg(v, u);
			}
	}
	cout.precision(10);
	cout << fixed;
	ans *= 2;
	cout << ((long double)ans / (long double)(n * (n - 1))) << endl;;
	
}
