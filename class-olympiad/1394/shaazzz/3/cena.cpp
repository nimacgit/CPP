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

const int maxn = 1000;
int a[maxn + 100];
int n;
int d[maxn + 100][maxn + 100];
int t[maxn + 100][maxn + 100];
bool mark[maxn + 100][maxn + 100];
int zero;

int abs(int a)
{
	if(a < 0)
		return a * -1;
	return a;
}

int dfs(int s, int use)
{
	if(mark[s][use])
		return d[s][use];
	if((s > zero && s - use > zero) || s < zero && s + use < zero)
		return 1e9;
	mark[s][use] = true;

	if(s > zero)
	{
		if(dfs(s - 1, use - 1) + t[s-1][use - 1] + abs(a[s] - a[s-1]) <
				dfs(s - use, use - 1) + t[s - use][use - 1] + abs(a[s] - a[s - use]))
		{
			t[s][use] = t[s-1][use - 1] + abs(a[s] - a[s-1]);
			d[s][use] = d[s - 1][use - 1] + t[s][use];
			mark[s][use] = true;
		}
		else
		{
			t[s][use] = t[s-use][use - 1] + abs(a[s] - a[s-use]);
			d[s][use] = d[s - use][use - 1] + t[s][use];
			mark[s][use] = true;
		}
		return d[s][use];
	}
	else
	{
		if(s == zero)
		{
			mark[s][use] = true;
			return d[s][use] = 1e9;
		}
		else
		{
			if(dfs(s + 1, use - 1) + t[s+1][use - 1] + abs(a[s] - a[s+1]) <
					dfs(s + use, use - 1) + t[s + use][use - 1] + abs(a[s] - a[s + use]))
			{
				t[s][use] = t[s+1][use - 1] + abs(a[s] - a[s+1]);
				d[s][use] = d[s+1][use - 1] + t[s][use];
				mark[s][use] = true;
			}
			else
			{
				t[s][use] = t[s+use][use - 1] + abs(a[s] - a[s+use]);
				d[s][use] = d[s+use][use - 1] + t[s][use];
				mark[s][use] = true;
			}
		}
		return d[s][use];
	}
}


int dyn()
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			d[i][j] = 1e9;
	}
	d[zero][0] = 0;
	t[zero][0] = 0;
	mark[zero][0] = true;
	int sum = 0;
	int tim = 0;
	for(int i = zero + 1; i < n; i++)
	{
		t[i][i - zero] = t[i - 1][i - zero - 1] + a[i] - a[i - 1];
		d[i][i - zero] = d[i - 1][i - zero - 1] + t[i][i - zero];
		mark[i][i -  zero] = true;

	}
	for(int i = zero - 1; i >= 0; i--)
	{
		t[i][zero - i] = t[i + 1][zero -i - 1] + a[i + 1] - a[i];
		d[i][zero - i] = d[i + 1][zero -i - 1] + t[i][zero - i];
		mark[i][zero - i] = true;
	}
	if(zero == 0)
		return dfs(n - 1, n - 1);
	else
		if(zero == n - 1)
			return dfs(0, n - 1);
	int s = dfs(n - 1, n - 1);
	s= min(s, dfs(0, n - 1));
	for(int i = 0; i < n; i++)
	{
		cerr << i << " i ";
		for(int j = 0; j < n; j++)
			cerr << d[i][j] << " ";
		cerr << endl;
	}
	return s;
}



int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	n++;
	a[n - 1] = 0;
	sort(a, a + n);
	zero = lower_bound(a, a + n, 0) - a;
	cout << dyn() << endl;
	return 0;
}
