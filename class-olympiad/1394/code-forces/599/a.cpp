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

int d1, d2, d3;

int main()
{
	cin >> d1 >> d2 >> d3;
	long long p1 = 2 * d1 + 2 * d2, p2 = d1 + d2 + d3 , p3 = 2*min(d1,d2) + 2 * d3;
	cout << min(p1, min(p2, p3)) << endl;
}
