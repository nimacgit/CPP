#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

const int maxn = 1e5 + 100;
int t, n, k;
int a[maxn];

void solve()
{
	int no = 0;
	for(int i = 0; i < n; i++)
	{
		if(a[i] == 0)
			no = 0;
		else
		{
			if(a[i] == 1)
			{
				if(no == 2)
				{
					cout << "No" << endl;
					return;
				}
				else
					no = 1;
			}
			else
			{
				if(no == 1)
				{
					cout << "No" << endl;
					return;
				}
				else
					no = 2;
			}
		}
	}
	cout << "Yes" << endl;
}

void inp()
{
	cin >> n >> k;
	fill(a, a+n, 0);
	for(int i = 0, x, y; i < k; i++)
	{
		cin >> x >> y;
		x--;
		y++;
		a[x] = y;
	}
}

int main()
{
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		inp();
		solve();
	}
}
