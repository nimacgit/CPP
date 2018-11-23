#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;
int n;
int maxi = 1e9;
int d[3];

int main()
{
	srand(time(NULL));
	n = rand() % maxi;
	cout << n << endl;
}
