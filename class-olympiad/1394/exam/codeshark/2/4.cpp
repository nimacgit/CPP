#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int delta = 12781;
const int maxn = 5;
long long d[maxn][maxn][maxn][maxn];


void dyn()
{
	d[0][0][0][0] = 1;
	for(int i = 1; i < maxn; i++)
	{
		d[i][0][0][0] = d[i - 1][0][0][0];
		for(int j = 1; j < maxn; j++)
		{
			d[i][j][0][0] = d[i][j - 1][0][0] * (i - j + 2) / j;
			for(int l = 1; l < maxn; l++)
			{
				d[i][j][l][0] = d[i][j][l - 1][0] * (i + j + 2 - l) / l;
				for(int k = 1; k < maxn; k++)
				{
					d[i][j][l][k] = d[i][j][l][k - 1] * (i + j + l + 2 - k) / k;
				}
			}
		}
	}
}

int main()
{
	long long sum = 0;
	dyn();
	cout << d[1][2][1][1] << endl;
	for(int i = 1; i <= 1; i++)
	{
		for(int j = 1; j <= 2; j++)
		{
			for(int l = 1; l <= 3; l++)
			{
				for(int k = 1; k <= 4; k++)
				{
					cout << d[i][j][l][k] << endl;
					sum = (sum + d[i][j][l][k]) % delta;
				}
			}
		}
	}
	cout << sum << endl;
}