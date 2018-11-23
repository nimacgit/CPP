#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second
using namespace std;

typedef pair<int, int> pie;

const int maxn = 2000;
int n, maxi = 0;
int a[maxn], b[maxn];
pair<int, int> d[maxn][maxn];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++)
		cin >> b[i];
	for(int i = 0; i < n; i++)
		for(int j = i; j < n; j++)
		{
			if(j == i)
				d[i][j]= mp(a[i], b[i]);
			else
				d[i][j] = mp(d[i][j - 1].F | a[j], d[i][j - 1].S | b[j]);
			maxi = max(maxi, d[i][j].F + d[i][j].S);
		}
	cout << maxi << endl;
	
}
