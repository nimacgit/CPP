#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

const int maxn = 1e4;
pie t[maxn];
int n, r, l;

int main()
{

	
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> l >> r >> n;
	for(int x, y, i = 0; i < n; i++)
	{
		cin >> x >> y;
		t[i] = mp(x, y);
	}
	sort(t, t+n);
	int mini = 100000, maxi = 0;
	for(int i = 0; i < n; i++)
	{
		int cr = 1, cl = 1, sr = 1, sl = 1;
		for(int j = 0; j < n; j++)
		{
			if(j != i)
			{
				if(t[i].F == t[j].F)
					sl++;
				if(t[i].S == t[j].S)
					sr++;
				if(t[i].F >= l && t[i].F <= r)
					if(t[j].S >= t[i].F && t[j].F <= t[i].F)
						cl++;
				if(t[i].S >= l && t[i].S <= r)
					if(t[j].S >= t[i].S && t[j].F <= t[i].S)
						cr++;
			}
		}
		if(t[i].F > l && t[i].F <= r)
			mini = min(mini, cl - sl);
		else if(t[i].F == l && t[i].F <= r)
			mini = min(mini, cl);
		if(t[i].F >= l && t[i].F <= r)
			maxi = max(maxi, cl);
		if(t[i].S >= l && t[i].S < r)
			mini = min(mini, cr - sr);
		else if(t[i].S >= l && t[i].S == r)
			mini = min(mini, cr);
		if(t[i].S >= l && t[i].S <= r)
			maxi = max(maxi, cr);
//		cerr << i << " " << t[i].F << " " << t[i].S << " " << mini << " " << maxi << endl;
	}
	if(mini == 100000)
		cout << 0 << " " << maxi << endl;
	else
		cout << mini << " " << maxi << endl;
}
