#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

const int maxn = 1e5;
int d[maxn];
int mo = 32441;
int n = 12345;
int main()
{
	d[1] = 1;
	for(int i = 2; i <= n ;i++)
		d[i] = ((d[i-1]) * (2*i)) % mo;
	cerr << d[1] << endl;
	cerr << d[2] << endl;
	cout << d[n] << endl;
}
