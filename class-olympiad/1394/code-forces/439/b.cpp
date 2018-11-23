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
int a[maxn];
long long n, x;
long long ans = 0;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> x;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	for(int i = 0; i < n; i++)
	{
		ans += x * a[i];
		x = max(x - 1, 1ll);
	}
	cout << ans << endl;
	
}
