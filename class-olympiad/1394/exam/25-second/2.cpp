#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;
const int maxn = 200;
int t[maxn][maxn];
int b[2][maxn][maxn];
int n = 100;
long long f[maxn][maxn];
long long mo = 59753, fm = 41;
long long sev = 7, thr = 3;
vector<pie> mv;

int main()
{
	b[1][0][0] = b[1][n - 1][0] = b[1][n - 1][n - 1] = b[0][n - 1] = 1;
	bool flag = true;
	for(int i = 0; i < n; i++)
	{
		
		for(int j = 0; j < n; j++)
		{
			mv.push_back(mp(i, j));
			f[i][j] = (sev * thr) % fm;
			thr = (thr * 3) % fm;
		}
		sev = (sev * 7) % fm;
	}
	long long co = 1;
	while(flag)
	{
		flag = check()
	}
}
