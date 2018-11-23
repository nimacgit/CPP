#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;
long long m, s, e;


long long getans(long long n)
{
	long long co = 0;
	for(long long a = 2; a * a * a <= n; a++)
			co+= n/(a*a*a);
	return co;
}

int main()
{
	long long ans = -1;
	cin >> m;
	s = 0;
	e = 1000000000000000000ll;
	while(s != e)
	{
		long long mid = (s+e)/2;
		if(getans(mid) >= m)
		{
			e = mid;
			if(getans(mid) == m)
				ans = mid;
		}
		else
			s = mid + 1;
	}
	cout << ans << endl;
}
