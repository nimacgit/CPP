#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

long long p, d;

int main()
{
	cin >> p >> d;
	long long temp = d;
	while(temp % p > p / 2)
		temp += d;
	cout << temp << endl;
}
