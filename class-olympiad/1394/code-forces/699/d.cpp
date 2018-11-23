#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

bool hh = false;
int n;
const int maxn = 3e5;
int a[maxn];
int h;
int par[maxn];
int co = 0;

int gpar(int v)
{
	if(par[v] != v)
		return par[v] = gpar(par[v]);
	return par[v];
}
void mrg(int v, int u)
{
	v = gpar(v);
	u = gpar(u);
	if(u != v)
		par[v] = u;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		par[i] = i;
		cin >> a[i];
		a[i]--;
		if(a[i] == i)
		{
			hh = true;
			h = i;
		}
	}
	for(int i = 0; i < n; i++)
	{
		if(gpar(i) != gpar(a[i]))
			mrg(i, a[i]);
		else
		{
			if(i != h)
			{
				co++;
				if(!hh)
				{
					hh = true;
					h = i;
					a[i] = i;
				}
				else
				{
					mrg(h, i);
					a[i] = h;
				}
			}
		}
	}
	for(int i = 0; i < n; i++)
		cout << a[i] + 1 << " ";
	cout << endl;


}
