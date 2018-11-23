#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair

using namespace std;

typedef pair<int, int> pie;
int d[40][40][60];
int t, n, m, k;
int main()
{
	cin >> t;
	for(int i = 1; i < 33; i++)
	{
		d[1][i][0] = d[1][i][i] = 0;
		for(int j = 1; j < i; j++)
			d[1][i][j] = 1;
	}
	for(int i = 2; i < 33; i++)
	{
		for(int j = 1; j < 33; j++)
		{
			d[i][j][0] = 0;
			for(int l = 1; l < 55; l++)
			{
//				cerr << "help " << i << " " << j << " " << l << endl;
				d[i][j][l] = 1e9;
				if(i * j == l)
					d[i][j][i * j] = 0;
				for(int i1 = 1; i1 < i; i1++)
					for(int l1 = 0; l1 <= l; l1++)
					{
						//cerr << "one " << i1 << " " << l1 << " " << i << " " << j << " " << l << endl;
						if(l1 <= i1 * j && l - l1 <= (i - i1) * j)
							d[i][j][l] = min(d[i][j][l], d[i1][j][l1] + d[i - i1][j][l - l1] + j * j); 
					}
				for(int j1 = 1; j1 < j; j1++)
					for(int l1 = 0; l1 <= l; l1++)
					{
//						cerr << "two " << j1 << " " << l1 << endl;
						if(l1 <= i * j1 && l - l1 <= (j - j1) * i)
							d[i][j][l] = min(d[i][j][l], d[i][j1][l1] + d[i][j - j1][l - l1] + i * i); 
					}
			}
		}
	}
	for(int i = 0; i < t; i++)
	{
		scanf("%d %d %d", &n, &m, &k);
		printf("%d\n", d[n][m][k]);
	}

}
