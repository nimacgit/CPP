#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const long long maxn = 80;
long long a[maxn][maxn];
long long d[maxn][maxn];


void dynamic()
{
	for(long long i = 0; i < maxn; i++)
		d[0][i] = a[0][i];
	for(int i = 1; i < maxn; i++)
	{
		for(int j = 0; j < maxn; j++)
		{
			if(j == 0)
				d[i][j] = d[i - 1][j] + a[i][j];
			else
				d[i][j] = min(d[i - 1][j], d[i][j - 1]) + a[i][j];
		}
		for(int j = maxn - 2; j >= 0; j--)
			d[i][j] = min(d[i][j], d[i][j + 1] + a[i][j]);
	}
}


int main()
{
	for(long long i = 0; i < maxn; i++)		
		for(long long j = 0; j < maxn; j++)
			cin >> a[j][i];
	dynamic();
	long long maxim = d[maxn - 1][0];
	for(int i = 0 ; i < maxn; i++)
		maxim = min(d[maxn - 1][i], maxim);
	cout << maxim << endl;

	
}