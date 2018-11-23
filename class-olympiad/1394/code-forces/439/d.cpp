#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;
const int maxn = 1e5 + 100;
long long n, m;
long long a[maxn], b[maxn];
long long bs, as, an, bn;
long long ans;


int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < m; i++)
		cin >> b[i];
	sort(a, a + n);
	sort(b, b + m);
	reverse(b, b + m);
	an = a[0];
	bn = b[0];
	for(int i = 0; i < n && a[i] == an; i++)
		as++;
	for(int i = 0; i < m && b[i] == bn; i++)
		bs++;
	while(bn > an)
	{
		if(as < bs)
		{
			if(as != n)
			{
				ans += min((a[as] - an), bn - an) * as;
				an = a[as];
				while(as < n && a[as] == an)
					as++;
			}
			else
			{
				ans += n * (bn - an);
				an = bn;
			}
			
		}
		else if(bs != m)
		{
			ans += min((bn - b[bs]), bn - an) * bs;
			bn = b[bs];
			while(bs < m && b[bs] == bn)
				bs++;
		}
		else
		{
			ans += m * (bn - an);
			bn = an;
		}
	}
	cout << ans << endl;
}
