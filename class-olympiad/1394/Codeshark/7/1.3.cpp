#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

const int maxn = 1e6;
int n = 1e5;
int d[maxn];
int mo = 32441;

int main()
{
	d[2] = 2;
	d[3] = 2;
	d[4] = 6;
	long long ans = 8;
	for(int i = 3; i <= n; i++)
	{
		d[i] = (2*d[i - 2] + d[i - 3]) % mo;
		ans += d[i];
		ans %= mo;
	}
	cout << ans << endl;

}
