#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

const int maxn  = 2000;
long long a[maxn+10][maxn+10];
long long d[maxn + 100][maxn + 100][4];
long long myvec[maxn * maxn + 100];

int main()
{
	for(int i = 1; i <= maxn * maxn; i++)
	{
		if(i < 56)
			myvec[i - 1] = ((long long) 100003 - (long long) 200003 * i + (long long)300007 * (long long)i * i * i) %1000000 - 500000;
		else
			myvec[i - 1] = (myvec[i - 25] + myvec[i - 56] + (long long)1000000) %1000000 - 500000;
	}
	cerr << myvec[9] << " " << myvec[99] << endl;
	for(int i = 0; i < maxn; i++)
		for(int j = 0; j < maxn; j++)
			a[i][j] = myvec[i * maxn + j];
	for(int i = 0; i < 4; i++)
		d[0][0][i] = a[0][0];
	for(int i = 1; i < maxn; i++)
	{
		d[0][i][0] = max(d[0][i - 1][0] + a[0][i], a[0][i]);
		d[0][i][1] = d[0][i][2] = d[0][i][3] = a[0][i];
		d[i][0][2] = max(d[i - 1][0][2] + a[i][0], a[i][0]);
		d[i][0][0] = d[i][0][1] = d[i][0][3] = a[i][0];
	}
	for(int i = 1; i < maxn; i++)
		for(int j = 1; j < maxn; j++)
		{
			d[i][j][0] = d[i][j][1] = d[i][j][2] = d[i][j][3] = a[i][j];
			d[i][j][0] += max(d[i][j - 1][0] , (long long)0);
			d[i][j][1] += max(d[i - 1][j - 1][1], (long long)0);
			d[i][j][2] += max(d[i - 1][j][2], (long long)0);
			if(j != maxn - 1)
				d[i][j][3] += max(d[i - 1][j + 1][3], (long long)0);
		}
	long long maxi = 0;
	for(int i = 0; i < maxn; i++)
		for(int j = 0; j < maxn; j++)
			for(int k = 0; k < 4; k++)
				maxi = max(maxi, d[i][j][k]);
	cout << maxi << endl;
}
