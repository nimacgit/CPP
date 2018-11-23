#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

const int maxn = 200 * 1000;
long long n;
long long a[maxn + 100];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	long long step = 0, sum = 0;
	for(int i = 0; i < n;i++)
	{
		step += abs(sum - a[i]);
		sum = a[i];
	}
	cout << step << endl;
}
