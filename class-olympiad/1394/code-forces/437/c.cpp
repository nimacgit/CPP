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
int a[maxn];
vector<pie> num;
int n, m;
vector<int> adj[maxn];
bool seen[maxn];

long long po(int v)
{
	long long sum = 0;
	for(auto u : adj[v])
		if(!seen[u])
			sum += a[u];
	seen[v] = true;
	return sum;
}


int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		cin >>  a[i];
		num.push_back(mp(a[i], i));
	}
	sort(num.begin(), num.end());
	reverse(num.begin(), num.end());
	for(int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x>> y;
		x--;
		y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	long long ans = 0;
	for(int i = 0; i < num.size(); i++)
		ans += po(num[i].S);
	cout << ans << endl;
}
