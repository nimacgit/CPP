#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

int mo = 55117;
long long n = 1e12;
long long ans = 0;

int main()
{
	while(n >= 4)
	{
		ans = (ans + n) % mo;
		n = (-1 + sqrt(1 + 8 * (n-3))) / 2 + 2;
		cout << n << endl;
	}
	ans += 6;
	cout << ans % mo << endl;
}
