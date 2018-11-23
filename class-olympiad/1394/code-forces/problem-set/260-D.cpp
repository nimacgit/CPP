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

set <pie> w,b;
int n;
vector<pair<pie, int> > edge;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for(int i = 0, c, v; i < n; i++)
	{
		cin >> c >> v;
		if(c)
			b.insert(mp(v, i));
		else
			w.insert(mp(v, i));
	}
	bool flag = false;
	while(!b.empty() && !w.empty())
	{
		pie ww = *w.begin(), bb = *b.begin();
		if(bb.F == ww.F)
			flag = true;
		edge.pb(mp(mp(bb.S, ww.S), min(bb.F, ww.F)));
		int temp = min(ww.F, bb.F);
		ww.F -= temp;
		bb.F -= temp;
		b.erase(b.begin());
		w.erase(w.begin());
		if(ww.F != 0)
			w.insert(ww);
		if(bb.F != 0)
			b.insert(bb);
		if(flag)
		{
			if(b.size() < w.size())
				b.insert(bb);
			else
				w.insert(ww);
			flag = false;
		}
	}
	for(int i = 0; i < n - 1; i++)
		cout << edge[i].F.F + 1 << " " << edge[i].F.S + 1 << " " << edge[i].S << endl;

}
