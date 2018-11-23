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
const int maxn = 200*1000 +100;
int n, m;
int a[maxn];
deque <pie> mys;
vector <pie> pos;
int main()
{
	int st = 0;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for(int i = 0, r, t; i < m; i++)
	{
		scanf("%d %d", &t, &r);
		while(!mys.empty() && mys.back().F <= r)
			mys.pop_back();
		if(mys.empty())
			mys.push_back(mp(r,t));
		else
			if(mys.back().S != t)
				mys.push_back(mp(r,t));
	}
	sort(a, a + mys[0].F);
	if(mys[0].S == 2)
		reverse(a, a+ mys[0].F);
	pos.push_back(mp(n - 1, mys[0].F));
	pos.push_back(mp(mys[0].F - 1, 0));
	mys.pop_front();
	while(!mys.empty())
	{
		int r = mys[0].F, t = mys[0].S;
		mys.pop_front();
		if(pos.back().F > pos.back().S)
		{
			pos.push_back(mp(pos.back().S, pos.back().S + r - 1));
			pos[pos.size() - 2].S += r;
		}
		else
		{
			pos.push_back(mp(pos.back().S, pos.back().S - r + 1));
			pos[pos.size() - 2].S -= r;
		}
	}
	for(int i = 0; i < pos.size(); i++)
	{
		pie nima = pos[pos.size() - 1 - i];
		if(nima.F < n && nima.S < n)
		{
			if(nima.F > nima.S)
				for(int j = nima.S; j <= nima.F; j++)
					printf("%d ", a[j]);
			else
				for(int j = nima.S; j >= nima.F; j--)
					printf("%d ", a[j]);
		}
	}
	printf("\n");

}
