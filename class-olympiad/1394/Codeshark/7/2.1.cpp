#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

const int maxn = 1e8;
int n = 50;
int mo = 32441;
int d[maxn];

int main()
{
	d[1] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 2*i; j <= n; j+=i)
			d[j] = (d[j] + d[i]) % mo;
	long long sum = 0;
	for(int i = 1; i <= n; i++)
	{
		cout << i << " " << d[i] << endl;
		sum = (sum + d[i]) % mo;
	}
	cout << sum << endl;
}
