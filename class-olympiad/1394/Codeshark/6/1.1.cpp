#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

int gcd(int a, int b)
{
	if(b == 0)
		return a;
	return gcd(b, a % b);
}

const int maxn = 1e7;
bool notp[maxn];
vector<int> p;
int n = 1e6;
long long sum = 0;
int mo = 34019;


void sieve()
{
	for(int i = 2; i < maxn; i++)
		if(!notp[i])
		{
			p.push_back(i);
			for(int j = 2; i * j < maxn; j++)
				notp[i * j] = true;
		}	
	
}

long long two[30];

int main()
{
	sieve();
	two[0] = 1;
	for(int i = 1; i < 25; i++)
		two[i] = two[i - 1] * 2;
	for(int i = 2; i <= n; i++)
	{
		int temp = i;
		int co = 0;
		cerr << "test" << endl;
		for(int k = 0; k < p.size() && temp > 1; k++)
		{
			if(temp % p[k] == 0)
			{
				co++;
				while(temp % p[k] == 0)
					temp /= p[k];
			
			}
		}
		sum = (sum + two[co]) % mo;
	}
	sum++;
	cout << sum << endl;
}
