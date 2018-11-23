#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;
const int maxn = 1e6+ 100;
long long n, m, sum;
long long a[maxn];
long long all;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	sort(a, a + n);

}
