#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

const int mo = 648481;
long long n = 1e6, sum = 0;

int main()
{
	for(long long i = 1; i <= n; i*=2)
		sum = (sum + min(i, n - i + 1) * min(i, n - i + 1)) % mo;
	cout << sum << endl;

}
