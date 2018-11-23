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
const int maxn = 100 * 1000 + 100;
int n;
pie pos[maxn];
long long a[maxn], b[maxn];
long long p[maxn], q[maxn];
int pr;
long double d = 0;


int main()
{
	cout.precision(7);
	cout << fixed;
	cin >> n >> pr;
	for(int i = 0; i < n; i++)
	{
		int temp1, temp2;
		scanf("%d %d", &temp1, &temp2);
		pos[i] = mp(temp1, temp2);
		int delta = temp2 / pr - (temp1 - 1) / pr;
		a[i] = delta;
		b[i] = temp2 - temp1 + 1 - delta;
	}
	d = 0;
	for(int i = 0; i < n; i++)
	{
		int x = i, y = (i + 1)%n;
		p[i] = b[x] * b[y];
		q[i] = (a[x] + b[x]) * (a[y] + b[y]);
		d += (long double)1 - (long double)p[i] / (long double)q[i];
	}
	cout << (long double)2000 * d << endl;
}

