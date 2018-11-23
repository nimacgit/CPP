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

const int maxn = 1e5 + 10, maxnum = 1e9, maxp = 3403;
vector<int> p;
vector<int> mv[maxp];
int a[maxn], parent[maxn];
map <int, int> par;
bool seen[maxn];
int n;


void sieve()
{
	for(long long i = 2; i*i <= maxnum; i++)
	{
		if(!seen[i])
		{
			p.pb(i);
			for(long long j = 2*i; j * j <= maxnum; j += i)
				seen[j] = true;
		}
	}
}

int getpar(int v)
{
	if(par[v] == 0)
		return par[v] = v;
	return (par[v] == v) ? v : (par[v]=getpar(par[v]));
}

void mrg(int v, int u)
{
	u = getpar(u);
	v = getpar(v);
	if(u < v)
		par[v] = u;
	else
		par[u] = v;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	p.pb(1e9 + 7);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sieve();
	for(int i = 0; i < n; i++)
	{
		int temp = a[i];
		for(int j = 1; j < p.size() && ((long long)p[j]*p[j] <= temp || (p[j] <= temp && p[p.size() - 1] >= temp)); j++)
			if(temp % p[j] == 0)
			{
				while(temp % p[j] == 0)
					temp /= p[j];
				if(parent[i] == 0)
					parent[i] = j;
				else
					mrg(parent[i], j);
			}
		if(temp != 1)
		{
			if(parent[i] != 0)
				mrg(parent[i], temp);
			else
				parent[i] = temp;
		}
	}
	for(int i = 0; i < n; i++)
		if(parent[i] != 0 && getpar(parent[i]) < maxp)
			mv[getpar(parent[i])].pb(a[i]);
	for(int i = 0; i < maxp; i++)
		if(mv[i].size()>1)
		{
			sort(mv[i].begin(), mv[i].end());
			reverse(mv[i].begin(), mv[i].end());
		}
	for(int i = 0; i < n; i++)
	{
		if(parent[i] == 0 || getpar(parent[i]) >= maxp)
			cout << a[i] << " ";
		else
		{
			int u = getpar(parent[i]);
			cout << mv[u][mv[u].size() - 1] << " ";
			mv[u].pop_back();
		}
	}
	cout << endl;
}
