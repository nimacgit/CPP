#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

long long n, no = 0;

int main()
{
	cin >> n;
	no += n / 2 + n /3 + n/ 5 + n/ 7 - n/6 - n/10 - n/14 - n/15 - n/21 - n/35 + n/70  + n/30 + n/42 + n/105 - n/210;
	cout << n - no << endl;
}
