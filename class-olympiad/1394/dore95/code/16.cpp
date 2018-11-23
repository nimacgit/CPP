#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second
#define pb push_back

using namespace std;

typedef pair<int, int> pie;


const int maxm = 1e6, maxn = 1e3;
int a[maxm];
vector<int> adj[maxn];
bool seen[maxn];
int h[maxn];
int n, m;
int par[maxn];

int bfs(int v)
{
	int pos;
	memset(seen, 0, sizeof(seen));
	seen[v] = true;
	h[v] = 0;
	pos = 0;
	a[0] = v;
	pos++;
	int ans = 1e9;
	h[v] = 0;
	for(int i = 0; i < pos; i++)
	{
		v = a[i];
		for(auto u : adj[v])
		{
			if(!seen[u])
			{
				par[u] = v;
				a[pos] = u;
				pos++;
				seen[u] = true;
				h[u] = h[v] + 1;
			}
			else
				if(u != par[v] && (h[u] == h[v] || h[u] == h[v] - 1))
					ans = min(ans, h[v] + h[u] + 1);
		}
	}
	return ans;

}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0, x, y; i < m; i++)
	{
		cin >> x >> y;
		x--;
		y--;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	int mini = 1e9;
	for(int i = 0; i < n; i++)
		mini = min(bfs(i), mini);
	if(mini == 1e9)
		cout << -1 << endl;
	else
		cout << mini << endl;
	
}
