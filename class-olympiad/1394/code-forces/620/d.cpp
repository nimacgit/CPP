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
const int maxn =  2 * 1000;
int n, m;
int a[maxn + 100], b[maxn + 100];
long long suma = 0;, sumb = 0, v;
int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		suma += a[i];
	}
	scanf("%d", &m);
	for(int i = 0; i < m; i++)
	{
		scanf("%d", &b[i]);
		sumb += b[i];
	}
	sort(b, b + m);
	v = suma - sumb;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(v < 
		}
	}

}
