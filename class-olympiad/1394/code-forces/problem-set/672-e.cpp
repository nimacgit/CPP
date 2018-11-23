#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

const int maxn = 1e6;
int a[maxn];
int n;
set<int> ms;
long long d[maxn];
set<int>::iterator it;
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i < n - 1; i++)
		cin >> a[i];
	d[1] = 1;
	ms.insert(a[0]);
	for(int i = 2; i < n; i++)
	{
		ms.insert(a[i - 1] - 1);
		it = ms.lower_bound(i);
		cerr << *it + 1 << endl;
		it++;
		d[i] += d[i - 1] + 1 + distance(ms.begin(), it);
		cerr << " d " << d[i] << endl;
	}
	long long sum = 0;
	for(int i = 0; i < n; i ++)
		sum += d[i];
	cout << sum << endl;
}
