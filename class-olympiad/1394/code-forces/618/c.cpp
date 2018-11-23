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

typedef pair<long long, long long> pie;
const int maxn = 100 * 1000 + 100;
int n;
pair<pie, int> dot[maxn];
int p[3];


bool comp(pair<pie, int> a, pair<pie, int> b)
{
	if(a.F.F == b.F.F)
		return a.F.S < b.F.S;
	return a.F.F < b.F.F;
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		dot[i] = mp(mp(x, y), i);
	}
	sort(dot, dot + n, comp);
	p[0] = dot[0].S;
	p[1] = dot[1].S;
	int pos = 2;
	if(dot[1].F.F == dot[0].F.F)
	{
		while(dot[pos].F.F == dot[1].F.F)
			pos++;
		p[2] = dot[pos].S;
	}
	else
	{
		if(dot[0].F.S == dot[1].F.S)
		{
			while(dot[pos].F.S == dot[1].F.S)
				pos++;
			p[2] = dot[pos].S;
		}
		else
		{
			long long dx1 = dot[1].F.F - dot[0].F.F, dx2 = dot[pos].F.F - dot[1].F.F,
			    dy1 = dot[1].F.S - dot[0].F.S, dy2 = dot[pos].F.S - dot[1].F.S;
			while(dy1 * dx2 == dy2 * dx1)
			{
				pos++;
				dx2 = dot[pos].F.F - dot[1].F.F;
				dy2 = dot[pos].F.S - dot[1].F.S;
			}
			p[2] = dot[pos].S;
		}
	}
	cout << p[0] + 1 << " " << p[1] + 1 << " " << p[2] + 1 << endl;
}

