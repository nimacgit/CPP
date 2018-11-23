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
pie edge[maxn];
pie w[maxn];
set<pie, std::greater<pie> > mins;
set<pie> maxs;
int par[maxn];
int n,m;


int gpar(int v)
{
	if(par[v] != v)
		return par[v] = gpar(par[v]);
	return v;
}
void merge(int v, int u)
{
	v = gpar(v);
	u = gpar(u);

	par[u] = v;
}

long long getmstmin(int sz)
{
	long long ans = 0;
	for(int i = 0; i < n; i++)
		par[i] = i;
	for(int i = 0; i < m; i++)
	{
		if(w[i].S <= sz)
		{
			int temp = w[i].F;
			int u = w[i].S;
			if(gpar(edge[u].F) != gpar(edge[u].S))
			{
				ans += temp;
				merge(edge[u].F, edge[u].S);
			}
		}
	}
	return ans;
}


long long getmstmax(int sz)
{
	long long ans = 0;
	for(int i = 0; i < n; i++)
		par[i] = i;
	for(int i = m - 1; i >= 0; i--)
	{
		if(w[i].S <= sz)
		{
			int temp = w[i].F;
			int u = w[i].S;
			if(gpar(edge[u].F) != gpar(edge[u].S))
				{
				ans += temp;
					merge(edge[u].F, edge[u].S);
			}
		}
	}
	return ans;
}

bool isok(int mid)
{
	if(getmstmin(mid) == getmstmax(mid))
		return false;
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0, x, y, temp; i < m; i++)
	{
		cin >> x >> y >> temp;
		x--;
		y--;
		edge[i] = mp(x,y);
		w[i] = mp(temp, i);
	}
	sort(w, w + m);
	int s = 0, e = m - 1;
	while(s != e)
	{
		int mid = (s+e+1)/2;
		if(isok(mid))
			e = mid - 1;
		else
			s = mid;
	}

	for(int i = 0; i <= s; i++)
		cout << 0;
	for(int i = s + 1; i < m; i++)
		cout << 1;
	cerr << endl;
}
