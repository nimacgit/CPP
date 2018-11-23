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
long long n,w;
int q[maxn + 100], l[maxn + 100];
long long d[maxn + 100];

void makinc()
{
	d[0] = q[0];
	for(int i = 1; i < n; i++)
	{
		long long sum = l[i] + l[i - 1], ind = i, mini = q[i] + d[i - 1];
		for(int j = i - 1; j >= 0 && sum <= w; j--)
		{
			if(q[ind] < q[j])
				ind = j;
			if(j == 0)
			{
				if(mini > q[ind])
					mini = q[ind];
			}
			else
			{
				if(mini > q[ind] + d[j - 1])
					mini = q[ind] + d[j - 1];
				sum += l[j - 1];
			}
		}
		d[i] = mini;
	}
}
int main()
{
	cin >> n >> w;
	for(int i = 0; i < n; i++)
		scanf("%d %d", &q[i], &l[i]);
	makinc();
	cout << d[n - 1] << endl;
	return 0;
}
