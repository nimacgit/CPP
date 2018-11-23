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

int mo = 648481;
long long p = (long long)100000000000000017;

long long gp(long long num, long long pw)
{
	if(pw == 0)
		return 1;
	cerr << pw << endl;
	long long ans = gp(num, pw/2);
	ans *= ans;
	ans %= mo;
	if(pw % 2 == 1)
		ans *= num;
	return ans % mo;
}


int main()
{
	cout << gp(2, p) - 1 << endl;
}
