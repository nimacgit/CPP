#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<long long, long long> pie;
const int maxn = 2e5+10, mo = 1e9+7;
long long seg[4*maxn], a[maxn];
pie lazy[4*maxn];
int n, q;

long long nima(long long a, long long d, long long sz)
{
	return (((sz*(sz-1)) / 2) * d + sz * a) % mo;
}

void build(int segnum=1, int s=0, int e=n)
{
	lazy[segnum] = {0, 0};
	if(s == e - 1)
	{
		seg[segnum] = a[s];
		return;
	}
	int mid = (s+e)/2;
	build(2*segnum, s, mid), build(2*segnum + 1, mid, e);
	seg[segnum] = seg[2*segnum]+seg[2*segnum + 1];
	seg[segnum]%=mo;
}

void shift(int segnum, long long s, long long e)
{
	if(e-s < 2)
		return;
	long long mid = (s+e)/2;
	lazy[2*segnum].F += lazy[segnum].F;
	lazy[2*segnum].S += lazy[segnum].S;
	lazy[2*segnum + 1].F += lazy[segnum].F+(mid-s)*lazy[segnum].S;
	lazy[2*segnum + 1].S += lazy[segnum].S;
	lazy[2*segnum + 1].F %= mo;
	lazy[2*segnum + 1].S %= mo;
	lazy[2*segnum].F %= mo;
	lazy[2*segnum].S %= mo;
	seg[2*segnum] += nima(lazy[segnum].F, lazy[segnum].S, mid - s);
	seg[2*segnum + 1] += nima((mid - s)*lazy[segnum].S + lazy[segnum].F, lazy[segnum].S, e - mid);
	lazy[segnum] = {0,0};


}

void update(long long l, long long r, long long a=1, long long d=1, int segnum=1, long long s=0, long long e=n)
{
	if(l <= s && e <= r)
	{
		shift(segnum, s, e);
		a = a + (s - l)*d;
		lazy[segnum] = {a, d};
		long long sz = e - s;
		seg[segnum] += nima(a, d, sz);
		return;
	}
	if(l >= e || r <= s)
		return;
	shift(segnum, s, e);
	long long mid = (s+e)/2;
	update(l, r, a, d, 2*segnum, s, mid), update(l, r, a, d, 2*segnum + 1, mid, e);
	seg[segnum] = (seg[2*segnum] + seg[2*segnum + 1])%mo;
}
long long get(int l, int r, int segnum=1, int s=0, int e=n)
{
	if(l <= s && e <= r)
		return seg[segnum];
	if(l >= e || r <= s)
		return 0;
	int mid = (s+e)/2;
	shift(segnum, s, e);
	return (get(l, r, 2*segnum, s, mid) + get(l, r, 2*segnum + 1, mid, e))%mo;
}




int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	build();
	string s;
	for(int i = 0, x, y; i < q; i++)
	{
		cin >> s >> x >> y;
		x--;
		if(s == "ask")
			cout << get(x, y)%mo << endl;
		else
			update(x, y);
	}
}
