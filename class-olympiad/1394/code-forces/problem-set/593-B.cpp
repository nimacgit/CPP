#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define S second
using namespace std;

typedef pair<long long, long long> pie;
const int maxn = 1000 * 100 + 1000;

bool comp(pie p1, pie p2)
{
	if(p1.first == p2.first)
		return p1.S < p2.S;
	return p1.first < p2.first;
}

pie p[maxn];
long long n, x1, x2;

int main()
{
	cin >> n >> x1 >> x2;
	for(int i = 0, k, b; i < n; i++)
	{
		cin >> k >> b;
		p[i] = make_pair(x1 * k + b, x2 * k + b);
	}
	sort(p, p + n, comp);
	long long s = p[0].S;
	for(int i = 1; i < n; i++)
	{
		if(p[i].S < s)
		{
			cout << "YES" << endl;
			return 0;
		}
		s = p[i].S;
	}
	cout << "NO" << endl;
}
