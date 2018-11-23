#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

int d[2000][2000];
int n = 1000;
int r[2000];
long long sum = 0;
int mo = 32441;

int main()
{
	d[1][0] = 1;
	d[0][1] = 1;
	d[0][0] = 1;
	r[0] = r[1] =  1;
	for(int i = 2; i <= n; i++)
	{
		d[0][i] = 2*d[0][i - 1];
		r[i] = d[0][i] %= mo;
	}
	for(int i = 1; i <= n; i++)
	{
		d[i][0] = d[i - 1][0] * 2;
		d[i][0] %= mo;
		r[0] *= 2;
		r[0] %= mo;
		sum = r[0];
		sum %= mo;
		for(int j = 1; j <= n; j++)
		{
			d[i][j] = sum + r[j];
			d[i][j] %= mo;
			r[j] += d[i][j];
			r[j] %= mo;
			sum += r[j];
			sum %= mo;
		}
	}
	cout << d[n][n] << endl;
}
