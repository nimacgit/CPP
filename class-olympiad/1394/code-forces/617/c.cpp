#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define ff first
#define ss second
using namespace std;

typedef pair<long long, long long> pie;
const int maxn = 2009;
pie pos[maxn];
pie f[2];
int n;
pie d[maxn];
long long d2[maxn];
long long maxim[maxn];

int main()
{
	cin >> n >> f[0].first >> f[0].second >> f[1].first >> f[1].second;
	for(int i = 0; i < n; i++)
	{
		int temp1, temp2;
		scanf("%d %d", &temp1, &temp2);
		pos[i] = mp(temp1, temp2);
	}
	for(int i = 0; i < n; i++)
		d[i] = mp((f[0].ff - pos[i].ff) * (f[0].ff - pos[i].ff) + (f[0].ss - pos[i].ss) * (f[0].ss - pos[i].ss), i);
	sort(d, d + n);
	for(int i = 0; i < n; i++)
		d2[i] = (f[1].ff - pos[d[i].ss].ff) * (f[1].ff - pos[d[i].ss].ff) + (f[1].ss - pos[d[i].ss].ss) * (f[1].ss - pos[d[i].ss].ss);
	maxim[0] = d2[n - 1];
	for(int i = 1; i < n; i++)
		maxim[i] = max(maxim[i - 1], d2[n - i - 1]);
	long long ans = maxim[n - 1];
	for(int i = 0; i < n; i++)
	{
		ans = min(ans, d[i].ff + maxim[n - i - 2]);
	}
	cout << ans << endl;
}

