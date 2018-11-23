#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define F first
#define S second

using namespace std;

typedef pair<long long ,long long> pie;
const int maxn = 10000000;
long long q, o, x, y, w;
map<long long, long long> mp;


int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> q;
	for(int i = 0; i < q; i++)
	{
		cin >> o >> x >> y;
		if(o == 1)
		{
			cin >> w;
			while(x != y)
			{
				if(x < y)
					swap(x, y);
				mp[x] += w;
				x /= 2;
			}
		}
		else
		{
			long long ans = 0;
			while(x != y)
			{
				if(x < y)
					swap(x, y);
				ans += mp[x];
				x /= 2;
			}
			cout << ans << endl;
		}
	}

}
