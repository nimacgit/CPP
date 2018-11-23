#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;
const int maxn = 1e6 + 1000;
bool notp[maxn];
vector<long long>p;
int d[maxn];
int mo = 648481;
long long sum = 0;
int n = 1e6;

void sieve()
{
	for(long long i = 2; i < maxn; i++)
	{
		if(!notp[i])
		{
			p.push_back(i);
			for(long long j = 2*i; j < maxn; j+=i)
				notp[j] = true;
		}
	}
}

int main()
{
	d[1] = d[4] = -2;
	sieve();
	for(int i = 0; i < p.size(); i++)
	{
		for(long long j = 1; j < p[i] && p[i] * j <= n; j++)
			d[j * p[i]] = -1;
	}
	for(int i = 1; i < 20; i++)
		cout << i << " " << d[i] << endl;
	for(int i = 1; i <= n; i++)
		sum += d[i] + 2;
	sum %= mo;
	cout << sum << endl;
}
