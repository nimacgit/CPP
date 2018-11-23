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

const int maxn = 1000 * 1000;
long long abs(long long a)
{
	if(a < 0)
		return (long long)-1 * a;
	return a;
}
long long x[2], y[2];


int main()
{
	cin >> x[0] >> y[0] >> x[1] >> y[1];
	long long dif1 = max(x[0] - x[1], x[1] - x[0]), dif2 = max(y[0] - y[1], y[1] - y[0]);

	cout << max(dif1, dif2) << endl;


}
