#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <set>
#include <bits/stdc++.h>
#define S second
#define F first
#define mp make_pair
using namespace std;


const int mo = 648481;
const int maxn = 10 * 1000* 1000;
long long n = 1000*1000*10;
bool notp[maxn];
vector<long long> p;

int gc(int a, int b)
{
	if(b == 0)
		return a;
	return gc(b, a % b);
}


void sieve()
{
	for(int i = 2; i < maxn; i++)
		if(!notp[i])
		{
			p.push_back(i);
			for(int j = 2*i; j < maxn; j+= i)
				notp[j] = true;
		}
}

long long co = 0;

int main()
{
	/*
	sieve();
	p[0] = 1;
	for(int i = 1; i < p.size(); i++)
	{
		bool flag = true;
		for(int j = 0; j < i && flag; j++)
		{
			flag = false;
			long long a = p[i]*p[j], b = p[i]*p[i] - p[j]*p[j], c = p[i]*p[i] + p[j]*p[j];
			c /= 2;
			b /= 2;
			for(long long d = 1; d < maxn && d*a <= n && d*b <= n && d*c <= n; d++)
			{
				flag = true;
				if(a < b)
				{
					co += a + 2*b + 3*c;
					co %= mo;
				}
				else
				{
					co += 2*a + b + 3*c;
					co %= mo;
				}	
			}
		}
	}
	*/
	for(long long o = 1; o <= sqrt(n); o++)
		for(long long p = 1; p <= o && o*o + p * p <= n; p++)
		{
			if((o + p) % 2 == 1 && gc(o, p) == 1)
			{
				long long a = 2 * o * p, b = o * o - p * p, c = o * o + p * p;
				if(b < a)
					swap(a, b);
				if(b > c)
					swap(b, c);
				if(b < a)
					swap(a, b);
				for(long long d = 1; d*a <= n && d * b <=n && d * c <= n; d++)
				{
//					cerr << d*a << " " << d*b << " " << d*c << endl;
					co += d*a + d*2*b + d*3*c;
					co %= mo;
				}
			}
		}
	cout << (((co*co)%mo)*co)%mo << endl;
}
