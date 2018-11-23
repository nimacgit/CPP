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
const int maxn = 1000 * 1000 + 100;
int n, l = 0, r = 0;
pie pr[maxn], pl[maxn];


int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		if(x > 0)
		{
			pr[r] = mp(x, y);
			r++;
			y = 100000 * y / x;
			x = 100000;
		}
		else
		{
			pl[l] = mp(x, y);
			l++;
			y = -1000000 * y / x;
			x = -11000000;
		}
	}
	sort(pl, pl + l);
	sort(pr, pr + r);
	for(int i = 0; i < n

}
