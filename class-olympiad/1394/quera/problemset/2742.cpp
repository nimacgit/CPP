#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;
const int maxn = 202, inf = 1e9;
int n, m, k;

int mat[maxn][maxn][3];


void mul(int u, int v)
{
	int p = 3 - v + u;
	p = max(p, 0);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			mat[i][j][p] = mat[0][i][u] + mat[j][0][v];
			for(int k = 1; k < n; k++)
				mat[i][j][p] = min(mat[i][j][p], mat[k][0][u] + mat[j][k][v]);
		}
}

void pow(int p, int v, int u)
{
	
	if(p % 2)
		mul(0, )
}


int main()
{

}
