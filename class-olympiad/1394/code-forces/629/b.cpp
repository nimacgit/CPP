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
const int maxn = 500;
int n;
int v[maxn], h[maxn];
char a[maxn][maxn];

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			cin >> a[i][j];
			if(a[i][j] == 'C')
			{
				v[i]++;
				h[j]++;
			}
		}
	long long sum = 0;
	for(int i = 0; i < n; i++)
		sum += v[i] * (v[i] - 1) / 2;
	for(int i = 0; i < n; i++)
		sum += h[i] * (h[i] - 1) / 2;
	cout << sum << endl;
}	
