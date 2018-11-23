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
const int maxn = 1000 * 1000 + 100;
typedef pair<int, int> pie;
string st, t;
bool all[4*maxn];
// 444 777 447 774
pair<pie, pie> seg[4*maxn];
int n, m;

void update(int s, int e, int x, int l, int r, bool flag)
{
	if(l <= s && e <= r)
	{
		if(flag)
			return;
		all[x] = all[x] ^ 1;
		swap(seg[x].F.F,seg[x].F.S);
		swap(seg[x].S.F, seg[x].S.S);
		return;
	}
	if(e <= l || r <= s)
	{
		if(flag)
		{
			all[x] ^= 1;	
			swap(seg[x].F.F,seg[x].F.S);
			swap(seg[x].S.F, seg[x].S.S);
		}
		return;
	}
	if(flag)
	{
		update(s, max(s + 1, l + 1), 2*x, l, r, 0);
		update(min(r - 1, e - 1), e, 2*x + 1, l, r, 0);
		seg[x].F.F = seg[2*x].F.F + seg[2*x + 1].F.F;
		seg[x].F.S = seg[2*x].F.S + seg[2*x + 1].F.S;
		seg[x].S.F = max(seg[2*x].F.F + seg[2*x+1].S.F, seg[2*x].S.F + seg[2*x+1].F.S);
		seg[x].S.S = max(seg[2*x].F.S + seg[2*x+1].S.S, seg[2*x].S.S + seg[2*x+1].F.F);
		return;
	}
	int mid = (s+e)/2;
	update(s, mid, 2*x, l, r, all[x]);
	update(mid, e, 2*x + 1, l, r, all[x]);
	seg[x].F.F = seg[2*x].F.F + seg[2*x + 1].F.F;
	seg[x].F.S = seg[2*x].F.S + seg[2*x + 1].F.S;
	seg[x].S.F = max(seg[2*x].F.F + seg[2*x+1].S.F, seg[2*x].S.F + seg[2*x+1].F.S);
	seg[x].S.S = max(seg[2*x].F.S + seg[2*x+1].S.S, seg[2*x].S.S + seg[2*x+1].F.F);
}
void pre(int s, int e, int x)
{
	if(e - s < 2)
	{
		bool flag = false;
		if(st[s] == '4')
			flag = true;
		seg[x].F.F = (int)flag;
		seg[x].F.S = (int)!flag;
		seg[x].S.F = 1;
		seg[x].S.S = 1;
		return;
	}
	int mid = (s+e)/2;
	pre(s, mid, 2*x);
	pre(mid, e, 2*x + 1);
	seg[x].F.F = seg[2*x].F.F + seg[2*x + 1].F.F;
	seg[x].F.S = seg[2*x].F.S + seg[2*x + 1].F.S;
	seg[x].S.F = max(seg[2*x].F.F + seg[2*x+1].S.F, seg[2*x].S.F + seg[2*x+1].F.S);
	seg[x].S.S = max(seg[2*x].F.S + seg[2*x+1].S.S, seg[2*x].S.S + seg[2*x+1].F.F);
}

int get()
{
	return seg[1].S.F;
}




int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	cin >> st;
	pre(0, n, 1);
	for(int i = 0, l ,r; i < m; i++)
	{
		cin >> t;
		if(t == "switch")
		{
			cin >> l >> r;
			l--;
			update(0, n, 1, l, r, 0);
		}
		else
			cout << get() << endl;
	}
}
