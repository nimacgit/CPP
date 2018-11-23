#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

long long n;

int main()
{
	cin >> n;
	n++;
	cout << n * (n - 1) * (long long)3 + 1 << endl;
}
