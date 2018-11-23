#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

const int maxn = 1e5;
long long n, a, b;
long double u;
long long gcd(long long p, long long q)
{
	if(q == 0)
		return p;
	return gcd(q, p % q);
}


int main()
{
	cin >> n;
	if(n == 1)
	{
		cout << -1 << endl;
		return 0;
	}
	for(int i = 1; i <= 1e8; i++)
	{
		if(n % i == 0)	
		{
			if(i%2 != 0 && (n/i)%2 !=0)
			{
				long long v = n / i;
				cout << (v * v - i * i) / 2 << " " << (v*v + i * i)/2 << endl;
				return 0;
			}
		}
		if((long double)sqrt(i * i + 2 * n) == (long double)(int(sqrt(i * i + 2 * n))))
		{
			int v = sqrt(i * i + 2 * n);
			if((v*v + i * i) % 2 == 0)
			{
				cout << v * i << " " << (v * v + i * i) / 2 << endl;
				return 0;
			}
		}
		
	}
	cout << -1 << endl;
}
