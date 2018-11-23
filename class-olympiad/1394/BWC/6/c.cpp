#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair

using namespace std;

typedef pair<int, int> pie;

long long mo = 1000000007;
long long n = 1e6 + 17;
long long nm = 1;
int main()
{
	long long ans = n * n;
	n--;
	ans %= mo;
	while(n > 1)
	{
		nm *= n;
		nm %= mo;
		n--;
	}
	cerr << nm << endl;
	long long tm = (nm * (nm-1))/2;
	tm %= mo;
	ans *= tm;
	ans %= mo;
	cout << ans << endl;
}
