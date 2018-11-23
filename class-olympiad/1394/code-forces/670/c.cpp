#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

const int maxn = 1e6;
int a[maxn];
int n, m;
pie mov[maxn];
vector<pie> po;
long long ans = 0;

int main()
{
	ios::sync_with_stido(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	int temp = a[0], co = 1;
	for(int i = 1; i < n; i++)
	{
		if(temp == a[i])
			co++;
		else
		{
			po.push_back(mp(co, i - 1));
			co = 0;
		}
	}
	sort(po.begin(), po.end());
	reverse(po.begin(), po.end());
	cin >> m;
	for(int i = 0, x, y; i < m; i++)
	{
		cin >> x >> y;
		mov[i] = mp(x, y);
	}
	sort(mov, mov + m);
	bool flag = false;
	int pos;
	int s = 0;
	while(!flag && s < po.size())
	{
		int u = a[po[s].S];
		pos = lower_bound(mov, mov + m, (po[s].F, -1)) - mov;
		if(mov[pos].F == u)
			flag = true;
		else if((pos < m && mov[pos + 1].F == u))
		{
			flag = true;
			pos++;
		}
		else
			s++;
	}
	if(s == po.size())
	{
		while(!flag)
		{
			int u = a[po[s].S];
			pos = lower_bound(mmov, mmov + m, mp(po[s].S, -1));
			if(mmov[pos].F == u)
				flag = true;
			else if(pos < m && mmov[pos + 1].r)
		}
	}
	else
	{
		while()
	}

}
