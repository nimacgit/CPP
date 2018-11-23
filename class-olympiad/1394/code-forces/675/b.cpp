#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

long long n, a, b, c, d, a1, a2, a3, a4;

int main()
{
	cin >> n >> a >> b >> c >> d;
	a1 = a + b;
	a2 = a + c;
	a3 = b + d;
	a4 = c + d;
	long long dif = max(a1, max(a2, max(a3, a4))) - min(a1, min(a2, min(a3, a4)));
	cout << max(n * n - n * dif,(long long) 0) << endl;
}
