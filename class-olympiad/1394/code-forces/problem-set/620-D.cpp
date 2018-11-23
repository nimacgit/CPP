#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define f first
#define s second
using namespace std;

typedef pair<int, int> pie;
const int maxn =  2 * 1000;
int n, m;
int a[maxn + 100], b[maxn + 100];
long long suma = 0, sumb = 0, v;
long long ans, pos[4];
vector<pair<long long, pie> > sa, sb;


int main()
{
	pos[0] = pos[1] = pos[2] = pos[3] = -1;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		suma += a[i];
	}
	scanf("%d", &m);
	for(int i = 0; i < m; i++)
	{
		scanf("%d", &b[i]);
		sumb += b[i];
	}
	v = suma - sumb;
	ans = v;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(abs(v - a[i] - a[i] + b[j] + b[j]) < abs(ans))
			{
				ans = v - 2 * a[i] + 2 * b[j];
				pos[0] = i;
				pos[1] = j;
			}
	if(m > 1 && n > 1)
	{
		for(int i = 0 ; i < n; i++)
			for(int j = i + 1; j < n; j++)
				sa.push_back(mp(a[i] + a[j], mp(i, j)));
		for(int i = 0; i < m; i++)
			for(int j = i + 1; j < m; j++)
				sb.push_back(mp(b[i] + b[j], mp(i, j)));
		sort(sb.begin(), sb.end());
		sort(sa.begin(), sa.end());
		int j = 0;
		for(int i = 0; i < sa.size(); i++)
		{
			while(j + 1 < sb.size() && abs(v - 2 * sa[i].f + 2 * sb[j].f) >= abs(v - 2 * sa[i].f + 2*sb[j + 1].f))
				j++;
			while(j > 0 && abs(v - 2 * sa[i].f + 2 * sb[j].f) > abs(v - 2 * sa[i].f + 2*sb[j - 1].f) )
				j--;
			if(abs(v + 2 * (sb[j].f - sa[i].f)) < abs(ans))
			{
				ans = v + 2 * (sb[j].f - sa[i].f);
				pos[0] = sa[i].s.f;
				pos[1] = sb[j].s.f;
				pos[2] = sa[i].s.s;
				pos[3] = sb[j].s.s;
			}
		}
	}
	cout << abs(ans) << endl;
	if(pos[0] == -1)
	{
		cout << 0 << endl;
		return 0;
	}
	if(pos[2] == -1)
		cout << 1 << endl;
	else
		cout << 2 << endl;
	cout << pos[0] + 1 << " " << pos[1] + 1 << endl; 
	if(pos[2] != -1)
		cout << pos[2] + 1 << " " << pos[3] + 1 << endl;

}

