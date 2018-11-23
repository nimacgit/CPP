#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

int n, t;
pair<int, pie> nod[10000];
int co = 1;
int ad = 1;
int maxi;

void dfs(int v)
{
	if(v >= maxi)
		return;
	if(nod[v].F > 4096)
	{
		nod[nod[v].S.F].F += (nod[v].F - 4096) / 2;
		dfs(nod[v].S.F);
		nod[nod[v].S.S].F += (nod[v].F - 4096) / 2;
		dfs(nod[v].S.S);
		nod[v].F = 4096;
	}
}


int main()
{
	int sum = 0;
	cin >> n >> t;
	if(n == 1)
	{
		if(t > 0)
			cout << 1 << endl;
		else
			cout << 0 << endl;
		return 0;
	}
	nod[0].S.F = 1;
	nod[0].S.S = 2;
	co = 1;
	ad = 2;
	maxi = (n * (n + 1)) / 2;
	nod[0].F = 0;
	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < ad; j++)
		{
			nod[co + j].F = 0;
			nod[co + j].S.F = co + ad + j + 1;
			nod[co + j].S.S = co + ad + j;
		}
		co += ad;
		ad++;
	}
	for(int i = 0; i < t; i++)
	{
		nod[0].F += 4096;
		dfs(0);
	}
	for(int i = 0; i < 1000;i++)
		if(nod[i].F == 4096)
			sum++;
	cout << sum << endl;
}
