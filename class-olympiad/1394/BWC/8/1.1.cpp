#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

long long mo = 648481;

int main()
{
	long long n = 1e9;
	n *= (long long)100000;
	cout << n << endl;
	cout << (((n % mo) * ((n + 1)%mo))/2 - 5) % mo << endl;
}
