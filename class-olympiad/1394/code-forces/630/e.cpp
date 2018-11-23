#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

long long x[2], y[2];

int main()
{
	 cin >> x[0] >> y[0] >> x[1] >> y[1];
	 cout << ((y[1] - y[0]) + 1) * (x[1] - x[0])/2 + (y[1] - y[0])/2 + 1 << endl;

}
