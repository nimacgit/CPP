#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

long long mo = 45161;
const int maxn = 1e6 + 1000;
long long n = 1000000;
long long ans = 0;
long long f[maxn];
long long hf[maxn];


long long gettwo(long long pw)
{
	if(pw == 0)
		return 1;
	long long ans = gettwo(pw/2);
	ans *= ans;
	ans %= mo;
	if(pw % 2 == 1)
		ans *= 2;
	return ans%mo;
}


int main()
{
	f[0] = 1;
	hf[0] = 1;
	f[1] = gettwo(n - 2) - 1;
	hf[1] = 2*f[1] + 1;
	hf[1] %= mo;
	for(long long i = 2; i <= n; i++)
	{
		f[i] = (f[i - 1] * (gettwo(n - 2) - 1)) % mo;
		hf[i] = (gettwo(n - 1) * hf[i - 1] - f[i - 1]) %mo;
	}
	for(long long i = 0; i < n; i++)
	{
		ans += (hf[n - i - 1] * gettwo(i * (n - 1)))%mo;
		ans %= mo;
	}
	cout << ans << endl;
}
