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
const int maxn = 3000;
int n;
long long d1[maxn], d2[maxn];
pie p[maxn];
long long sum = 0;
int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		x--;
		y--;
		d1[x + y]++;
		d2[999 - x + y]++;
	}
	for(int i = 0; i < maxn - 3; i++)
	{
		sum += (long long)d1[i] * (d1[i] - 1) / (long long)2;
		sum += (long long)d2[i] * (d2[i] - 1) / (long long)2;
	}
	cout << sum << endl;

}	
