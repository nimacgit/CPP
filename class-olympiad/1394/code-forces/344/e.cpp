#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;
const int maxn = 1e5 + 1000;
long long n, m;
long long h[maxn], p[maxn];



bool check(long long len)
{
	long long pos = 0;
	for(int i = 0; i < n; i++)	
	{
		long long x = len;
		if(p[pos] >= h[i])
		{
			while(pos < m && p[pos] - h[i] <= x)
				pos++;
			if(pos == m)
				return true;
		}
		else
		{
			if(h[i] - p[pos] > len)
				return false;
			long long temp = h[i] - p[pos], tem = pos;
			x -= temp;
			while(pos < m && p[pos] <= h[i])
				pos++;
			tem = pos;
			while(tem < m && 2*(p[tem] - h[i]) <= x)
			{
				if(p[pos] - h[i] <= x - temp)
					pos++;
				tem++;
			}
			while(pos < m && p[pos] - h[i] <= x - temp)
				pos++;
			pos = max(tem, pos);
			if(pos == m)
				return true;
		}
	}
	if(pos == m)
		return true;
	else
		return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> h[i];
	for(int i = 0; i < m; i++)
		cin >> p[i];
	long long s = 0, e = 100000000000ll, mid;
	while(e != s)
	{
		mid = (s + e)/2ll;
		if(check(mid))
			e = mid;
		else
			s = mid + 1;
	}
	cout << s << endl;
}
