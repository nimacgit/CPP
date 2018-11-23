#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int maxn = 80;
int a[maxn][maxn];
int d[maxn][maxn];

void dynamic()
{
	d[0][0] = a[0][0];
	for(int i = 1; i < maxn; i++)
		d[0][i] = d[0][i - 1] + a[0][i];
	for(int i = 1; i < maxn; i++)
	{
		for(int j = 0; j < maxn; j++)
		{
			if(j == 0)
				d[i][j] = a[i][j] + d[i - 1][j];
			else
				d[i][j] = min(d[i - 1][j], d[i][j - 1]) + a[i][j];
		}
	}
}


int main()
{
	for(int i = 0; i < maxn; i++)
		for(int j = 0; j < maxn; j++)
			cin >> a[i][j];
	dynamic();
	cout << d[maxn - 1][maxn - 1] << endl;
}