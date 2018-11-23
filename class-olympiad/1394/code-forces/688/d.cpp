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
long long n, k;
long long km = 1;

long long gc(long long a, long long b)
{
	if(b == 0)
		return a;
	return gc(b, a % b);
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for(long long i = 0, x; i < n; i++)
	{
		cin >> x;
		x = gc(x, k);
		km = (km * x) / gc(km, x);
	}
	if(km % k == 0)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

}

