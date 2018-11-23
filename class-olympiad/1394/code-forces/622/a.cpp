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
long long n;


int main()
{
	cin >> n;
	long long pos = (-1 + sqrt(8 * n + 1 )) / 2;
	if((pos * (pos + 1)) / 2 == n)
		cout << pos << endl;
	else
		cout << n - (pos * (pos + 1)) / 2 << endl;

}
