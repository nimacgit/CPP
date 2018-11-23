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
const int maxor = 1000 * 1000;
const int maxn = 50 * 1000;
int seg[4 * maxn];
int xr[maxor + 100];
int a[maxn + 100];
int n, m;


void pre()
{
	for(int i = 1; i <= maxor; i++)
		xr[i] = xr[i - 1] ^ i;	
}

void make(int start, int end,int segnum)
{
	if(start == end - 1)
}

int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	pre();
	for(int i = 0, x, y; i < m; i++)
	{
		scanf("%d %d", &x, &y);
		printf("%d\n", d[x][y]);
	}
}
