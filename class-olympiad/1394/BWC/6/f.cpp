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

const long long mo = 1e9 + 7;
const long long maxn = 1e7;
long long int n;
bool notp[maxn + 1000];
vector<long long> p;


long long pw(long long a, long long b)
{
	if(b == 0)
		return 1;
	long long tem = pw(a, b / 2);
	tem *= tem;
	tem %= mo;
	if(b % 2)
		tem *= a;
	return tem % mo;
}

void sieve()
{
	for(int i  = 2; i < maxn; i++)
	{
		if(!notp[i])
		{
			p.push_back(i);
			for(int j = 2*i; j < maxn; j+=i)
				notp[j] = true;
		}
	}

}

long long calcsum(long long a, long long pr)
{
	long long ans = 0;
	long long tem = pr;
	while(tem <= a)
	{
		ans += a / tem;
		tem *= pr;
		if(ans > maxn*maxn || tem > maxn*maxn)
			cout << "err" << endl;
	}
	return ans;
}

long long f(long long a, long long b)
{
	long long ans = 1;
	for(int i = 0; i < p.size() && p[i] <= a; i++) 
	{
		ans *= pw(p[i], calcsum(a, p[i])-calcsum(b, p[i])-calcsum(a-b, p[i]));
		ans %= mo;
	}
	return ans;
}

int main()
{
	sieve();
	cerr << pw(2, 0) << " " << pw(2, 1) << "  " << f(2, 1) << endl; 
	cerr << f(5, 2) << endl;
	for(n = 1717171; n <= 1717171; n++)
	{
		long long ans = 0;
		for(long long i = 1; i <= n; i*=2)
		{
			ans += f(n, i)%mo;
			cerr << n << " " << i << " " << f(n, i) << endl;
			ans %= mo;
		}
		ans %= mo;
		cout << ans << endl;
	}
}
