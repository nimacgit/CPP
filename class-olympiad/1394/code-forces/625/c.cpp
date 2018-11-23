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
const int maxn = 1000;
int n, k;
int a[maxn][maxn];

int main()
{
	cin >> n >> k;
	int maxi = n * n;
	int mini = 1;
	long long sum = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n - k  + 1; j++)
		{
			a[i][n - j - 1] = maxi;
			maxi--;
		}
		for(int j = 0; j < k - 1; j++)
		{
			a[i][j] = mini;
			mini++;
		}
	}
	for(int i = 0; i < n; i++)
		sum += a[i][k - 1];
	cout << sum << endl;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}

}
