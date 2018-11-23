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

const int maxn = 1e5 + 100;
vector<pie> adj[maxn];
bool isbak[maxn];
int n, m;
int a[maxn];
int k;

int main()
{
	cin >> n >> m >> k;
	for(int i = 0,x , y, w; i < m; i++)
	{
		cin >> x >> y >> w;
		x--;
		y--;
		adj[x].pb(mp(y, w));
		adj[y].pb(mp(x, w));
	}
	for(int i = 0; i < k; i++)
	{
		cin >> a[i];
		a[i]--;
		isbak[a[i]] = true;
	}
	int mini = 1e9+2;
	for(int i = 0; i < k; i++)
			for(auto u : adj[a[i]])
				if(!isbak[u.F])
					mini = min(mini, u.S);
	if(mini == (int)(1e9+2))
		cout << -1 << endl;
	else 
		cout << mini << endl;
	
}
