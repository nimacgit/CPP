#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair

using namespace std;

typedef pair<int, int> pie;
set<int> ls;
set<int,greater<int> > hs;
int n, m, c, r;
const int maxn = 1000;
int a[maxn][maxn];

void makebal()
{
	while(hs.size() - ls.size() > 2)
	{
		ls.insert(*hs.begin());
		hs.erase(hs.begin());
	}
}
void add(int v)
{
	hs.insert(v);
}
void rm(int v)
{
	if(*hs.begin() < v)
		ls.erase(v);
	else
		hs.erase(v);
}

int getans()
{
	if((hs.size() - ls.size()) % 2 == 0)
		return *hs.begin();
	auto it = hs.begin();
	it++;
	return *it;
}

void plus(int &y)
{
	if(y == )
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> a[i][j];
	cin >> c >> r;
	for(int i = 0; i < c; i++)
		for(int j = 0; j < r; j++)
			add(a[i][j]);
	for(int i = 0; i < n - c; i++)
	{
		for(int k = 0; k < m - r; k++)
		{
		
			plus(&j);
		}
	}
}
