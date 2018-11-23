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
long long n, k, x = 0;
vector<long long> p, p2, p3, p4, mv;
bool notp[maxn];
long long ans = 0, sum = 0, mo = 45161;

void sieve()
{
	for(long long i = 2; i < n; i++)
		if(!notp[i])
		{
			if(i * i <= n)
				p2.push_back(i*i);
			p.push_back(i);
			for(long long j = 2*i; j <= n; j+=i)
				notp[j] = true;
		}
	for(long long i = 2; i * i * i <= n; i++)
		if(!notp[i])
			p3.push_back(i*i*i);
	for(long long i = 2; i * i * i * i <= n; i++)
		if(!notp[i])
			p4.push_back(i*i*i*i);
}

void add3()
{
	for(int i = 0; i < p2.size(); i++)
	{
		int co = 0;
		for(int j = 0; j <= i && p2[i] * p[j] <= n; j++)
			co++;
		mv.push_back(co);
	}
}
void add4()
{
	for(int i = 0; i < p.size(); i++)
	{
		for(int j = 0; j < i && p[i] * p[j] <= n; j++)
		{
			int co = 0;
			for(int k = 0; k <= j && p[i] * p[j] * p[k] <= n; k++)
				co++;
			mv.push_back(co);
		}
	}
	for(int i = 0; i < p3.size(); i++)
	{
		int co = 0;
		for(int j = 0; j <= i && p3[i] * p[j] <= n; j++)
			co++;
		mv.push_back(co);
	}
}
void add5()
{
	cerr << p4.size() << " " << p3.size() << " " << p2.size() << " " << p.size() << endl;
	for(int i = 0; i < p4.size(); i++)
	{
		int co = 0;
		for(int j = 0; j <= i && p4[i] * p[j] <= n; j++)
			co++;
		mv.push_back(co);
	}
}

int main()
{
	cin >> n >> k;
	sieve();
	add3();
	add4();
	add5();
	sort(mv.begin(), mv.end());
	cerr << mv.size() << endl;
	long long begin = 0, x = 0;
	for(long long j = 1; j <= k; j++)
	{
		while(x + mv[begin] <= j && begin < mv.size())
		{
			x += mv[begin];
			begin++;
		}
		long long tem = (x*begin)%mo;
		tem *= tem;
		tem %= mo;
		ans += tem;
		ans %= mo;
	}
	cerr << ans << endl;
}
