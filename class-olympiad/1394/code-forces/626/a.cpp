#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second
using namespace std;

typedef pair<int, int> pie;

const int maxn = 500;
int n;
char a[maxn];
pair<pie, pie> d[maxn];

int main()
{
	cin >> n;
	d[0] = mp(mp(0, 0), mp(0, 0));
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		if(a[i] == 'U')
		{
			
			d[i + 1] = mp(mp(d[i].F.F + 1, d[i].F.S), mp(d[i].S.F, d[i].S.S));
		}
		else if(a[i] == 'D')
		{

			
			d[i + 1] = mp(mp(d[i].F.F, d[i].F.S + 1), mp(d[i].S.F, d[i].S.S));
		}
		else if(a[i] == 'L')
		{	
			d[i + 1] = mp(mp(d[i].F.F, d[i].F.S), mp(d[i].S.F + 1, d[i].S.S));
		}
		else
		{
			d[i + 1] = mp(mp(d[i].F.F, d[i].F.S), mp(d[i].S.F, d[i].S.S + 1));
		}
	}
	int cnt = 0;
	for(int i = 0; i <= n; i++)
	{
		for(int j = i + 1; j <= n; j++)
		{
			int u = d[j].F.F - d[i].F.F, down = d[j].F.S - d[i].F.S, l = d[j].S.F - d[i].S.F, r = d[j].S.S - d[i].S.S;

			if(u == down && r == l)
				cnt++;
		}
	}
	cout << cnt << endl;


}
