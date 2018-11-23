#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

const int maxn = 2*100 * 1000;
set<pie> ms;
int n, m;
queue<int> mv[maxn];
bool isin[maxn];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 0, t, v, q; i < n; i++)
	{
		cin >> t;
		if(t == 1)
		{
			cin >> q >> v;
			mv[q].push(v);
			if(!isin[q])
			{
				ms.insert(mp(v, q));
				isin[q] = true;
			}
		}
		else
		{
			if(ms.size() == 0)
				cout << -1 << " ";
			else
			{
				q = ms.begin()->S;
				cout << ms.begin()->S << " ";
				ms.erase(ms.begin());
				mv[q].pop();
				if(mv[q].size() == 0)
					isin[q] = false;
				else
					ms.insert(mp(mv[q].front(), q));
			}
		}
	}
	cout << endl;
}
