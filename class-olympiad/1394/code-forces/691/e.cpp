#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

const int maxn = 1000;
long long n, k;
long long a[maxn];
int d[maxn];
long long mat[maxn][maxn], mat2[maxn][maxn], temp[maxn][maxn];

void mult()
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			temp[i][j] = 0;
			for(int k = 0; k < n; k++)
				temp[i][j] += mat[i][k] * mat2[k][j];
		}
	}
}

void pw(long long p)
{
	if(p %)

}

int main()
{
	cin >> n >> k;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		for(int j = 0; j <= i; j++)
			if(__builtin_popcountll(a[i] ^ a[j]) % 3 == 0)
				mat[i][j] = 1;
	}
	pw(k - 1);
	for(int i = 0; i < n; i++)
		cerr << d[i] << endl;
}
