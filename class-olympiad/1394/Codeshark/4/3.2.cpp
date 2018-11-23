#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

const int maxn = 1e8;
int mo = 55117;
long long deg[maxn];
long long two[30];
long long lg[maxn];
long long pa = 3;
int pos = 0;
int maxh, maxi;
bool seen[maxn];

void dfs(int v, int h)
{
	cerr << " check " << v << " " << h << endl;
	seen[v] = true;
	if(h > maxh)
	{
		maxh = h;
		maxi = v;
	}

	for(int i = pa - 1; i >= 0 && two[i] > v; i--)
		if(deg[v + two[i]] > 0)
			dfs(v + two[i], h + 1);
	if(!seen[v - lg[v]])
		if(deg[v - lg[v]] > 0)
			dfs(v - lg[v], h + 1);

}

bool f(int v)
{
	seen[v] = true;
	if(v == maxi)
	{
		deg[v]--;
		return true;
	}
	for(int i = pa - 1; i >= 0 && two[i] > v; i--)
		if(deg[v + two[i]] > 0)
			if(f(v + two[i]))
			{
				deg[v] -= 2;
				return true;
			}
	if(!seen[v - lg[v]])
		if(deg[v - lg[v]] > 0)
			if(f(v - lg[v]))
			{
				deg[v] -= 2;
				return true;
			}
	return false;	

}


void pre()
{
	two[0] = 1;
	for(int i = 1; i < 22; i++)
		two[i] = 2 * two[i - 1];
	lg[1] = 0;
	lg[0] = 0;
	for(int i = 2; i < maxn - 2; i++)
		lg[i] = lg[i/2] + 1;
	for(int i = 0; i < two[pa]; i++)
		deg[i] = pa - 1 - lg[i];
}

int main()
{
	pre();
	int co = 0;
	while(pos < two[pa])
	{
		co++;
		maxh = 0; maxi = 0;
		memset(seen, 0, sizeof seen);
		dfs(pos, 0);
		memset(seen, 0, sizeof seen);
		int temp = maxi;
		dfs(maxi, 0);
		cerr << "bow " << pos << " " << temp << " " << maxi << endl;
		memset(seen, 0, sizeof seen);
		f(temp);
		deg[temp]++;
		while(deg[pos] == 0 && pos < two[pa])
			pos++;
	}
	cout << co << endl;
}
