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
long double d, v1, v2, l;

int main()
{
	cout.precision(7);
	cout << fixed;
	cin >> d >> l >> v1 >> v2;
	cout << (l - d) / (v1 + v2) << endl;

}
