#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;
const int maxn = 1000 * 100 + 1000;
long long a[maxn], rn[maxn], ln[maxn];
long long n;


int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	int last = -1, first = -1, q;
	for(int i = 0; i < n; i++)
	{
		if(a[i] < 0)
		{
			if(first == -1)
			{
				first = i;
				q = first;
			}
		}

	}
}
