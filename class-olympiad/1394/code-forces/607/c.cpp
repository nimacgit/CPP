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

const int maxn = 1000 * 100;
int n;
pie a[10 * maxn + 100];
int sum[10 * maxn + 100];
int d[maxn + 100];


int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int temp1, temp2;
		scanf("%d %d", &temp1, &temp2);
		a[i] = mp(temp1, temp2);
		sum[temp1] = 1;
	}
	sort(a, a + n);
	int co = 0;
	for(int i = 0; i < 10 * maxn + 1; i++)
	{
		if(sum[i] == 1)
		{
			co++;
			sum[i] = co - 1;
		}
		else
			sum[i] = co;
	}
	d[0] = 0;
	int minim = n;
	for(int i = 0; i < n; i++)
	{
		
		int kill = 0;
		int pos = max(0, a[i].first - a[i].second);
		kill += i + 1 - sum[pos] - 1 + d[sum[pos]];
		d[i + 1] = kill;
		kill += n - i - 1;
		minim = min(minim, kill);
	}
	cout << minim << endl;
}

