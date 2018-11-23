#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;
const long long maxn = 1e8;
bool notp[maxn];
vector<long long> mv;

void sieve()
{
	for(int i = 2; i < maxn; i++)
		if(!notp[i])
		{
			mv.push_back(i);
			for(int j = 2; i * j < maxn; j++)
				notp[i * j] = true;
		}
}

int mo = 34019;
long long sum = 0;
long long n = (long long)1e15 - 1;

bool isp(long long num)
{
	for(int i = 0; (long long)mv[i]*mv[i] <= num; i++)
		if(num % mv[i] == 0)
			return true;
	return false;
}

long long f(long long a, long long mul)
{
	long long temp = a;
	a /= mul;
	while(isp[a] || ((mul == 2) && isp[temp - a]))
		a--;
	return a;
}


int main()
{
	sieve();
	notp[1] = true;
	long long x, y, z, maxans = 0;
	x = f(n, 3);
	y = f(n - x, 2);
	z = n - x - y;
	maxans = (x * x)%mo + (y*y)%mo + (z*z)%mo;
	if(x >= y)
		cout << "abol" << endl;
	//		cerr << maxans << endl;
	sum = (sum + maxans) % mo;
	cout << sum % mo << endl;
}
