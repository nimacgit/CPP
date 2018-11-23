#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;



int main()
{
	unsigned long long n, ans = 0;
	long long f[40];
	cin >> n;
	f[0] = 1;
	for(int i = 1; i < 30; i++)
		f[i] = f[i - 1] * 4;
	ans += 2 * 3 * f[n - 3];
	for(int i = 1; i < n - 2; i++)
		ans += (3*f[i - 1] * f[n - 2 - i - 1] * 3);
	cout << ans * 4 << endl;
}
