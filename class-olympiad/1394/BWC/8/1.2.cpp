#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

const int maxn = 10000 + 1000;
long long d[maxn][maxn];
long long b[maxn];
bool notp[maxn];
int n = 1000 * 10;
vector<int> p;
const int mo = 648481;
void sieve()
{
	for(int i = 2; i < maxn; i++)
	{
		if(!notp[i])
		{
			p.push_back(i);
			for(int j = 2; i * j < maxn; j++)
				notp[i * j] = true;
		}
	}
}

int main()
{
	sieve();
	for(int i = 0; i < maxn; i++)
		d[1][i] = 0, d[0][i] = 1;
	for(int i = 2; i < maxn; i++)
	{
		if(i > 2)
			d[i][0] = 0;
		else
			d[i][0] = 1;
		for(int j = 1; j < p.size(); j++)
		{
			d[i][j] = 0;
			for(int k = 0; k * p[j] <= i && k < p[j]; k++)
			{
				d[i][j] += (d[i - k * p[j]][j - 1]) % mo;
			}
		}
	}
	long long sum = 0;
	for(int i = 1; i <= n; i++)
	{
			b[i] = d[i][p.size() - 1];
			sum = (sum + d[i][p.size() - 1]) % mo;
	}
	for(int i = 1; i < 20; i++)
		cout << b[i] << endl;
	cout << sum << endl;
	
}
