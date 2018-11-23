#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second
#define pb push_back


using namespace std;

typedef pair<int, int> pie;

const int maxn = 3e5;
long long n, k, m, d, r, x;
struct nima
{
	long long l, r, all, d;
	nima(long long& l, long long& r, long long& all, long long& d):l(l), r(r), all(all), d(d){};
	nima(){};
};
nima seg[4*maxn];
long long a[maxn];

void build(int segnum=1, int s=0, int e=n)
{
	if(s == e - 1)
	{
		long long temp = -1*k;
		seg[segnum] = nima(temp, temp, temp, temp);
		return;
	}
	int mid = (s+e)>>1;
	build(2*segnum, s, mid);
	build(2*segnum+1, mid, e);
	seg[segnum].all = seg[2*segnum].all + seg[2*segnum + 1].all;
	seg[segnum].r = max(seg[2*segnum + 1].r, seg[2*segnum].r + seg[2*segnum + 1].all);
	seg[segnum].l = max(seg[2*segnum].l, seg[2*segnum].all + seg[2*segnum + 1].l);
	seg[segnum].d = max(max(seg[2*segnum].d, seg[2*segnum + 1].d), seg[2*segnum].r + seg[2*segnum + 1].l);
}

void update(int p, long long val, int segnum=1, int s=0, int e=n)
{
	if(e - s == 1)
	{	
		long long temp = seg[segnum].all + val;
		seg[segnum] = nima(temp, temp, temp, temp);
		return;
	}
	int mid = (s+e)>>1;
	if(p < mid)
		update(p, val, 2*segnum, s, mid);
	else
		update(p, val, 2*segnum + 1, mid, e);
	seg[segnum].all = seg[2*segnum].all + seg[2*segnum + 1].all;
	seg[segnum].r = max(seg[2*segnum + 1].r, seg[2*segnum].r + seg[2*segnum + 1].all);
	seg[segnum].l = max(seg[2*segnum].l, seg[2*segnum].all + seg[2*segnum + 1].l);
	seg[segnum].d = max(max(seg[2*segnum].d, seg[2*segnum + 1].d), seg[2*segnum].r + seg[2*segnum + 1].l);
}	

string get()
{
	return (k*d < seg[1].d) ? "NO" : "YES";
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k >> d;
	build();
	for(int i = 0 , p; i < m; i++)
	{
		cin >> p >> x;
		p--;
		update(p, x);
		cout << get() << endl;
	}

}
