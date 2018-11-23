#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair

using namespace std;

typedef pair<int, pair<int,int> > pie;
const int maxn = 1000 * 100;
pie a[maxn + 100];
int n, m;
pair<int, int> d[maxn + 100];


bool comp(pie i, pie j)
{
	if(i.first == j.first)
		return j.second.first < i.second.first;
	return i.first < j.first;
}


int main()
{
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		a[i] = mp(x, mp(y, i));
	}
	sort(a, a + m, comp);
	long long vert = 0, use = 0;
	for(int i = 0; i < m; i++)
	{
		if(a[i].second.first)
			vert++;
		else
			if(use >= vert * (vert + 1) / 2)
			{
				cout << -1 << endl;
				return 0;
			}
		use++;

	}
	int s1 = 0, s2 = 1, l2 = 3;
	for(int i = 0; i < m; i++)
	{
		if(a[i].second.first)
		{
			d[a[i].second.second] = mp(s1 + 1, s1 + 2);
			s1++;
		}
		else
		{
			d[a[i].second.second] = mp(s2, l2);
			l2++;
			if(l2 > n)
			{
				l2 = s2 + 3;
				s2++;
			}
		}
	}
	for(int i = 0; i < m; i++)
		cout << d[i].first << " " << d[i].second << endl;
		
		
}
