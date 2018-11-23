#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

const long long mo = 59753;
long long n = 1e6;

int main()
{
	long long num[2] = {0,1};
	long long mul = 1;
	for(int i = 0; i < n; i++)
	{
		mul *= 6;
		mul %= mo;
		num[0] = (num[0] + 2*num[1]) % mo;
		num[1] = (num[0] + mul) % mo;
	}
	cout << num[0] << endl;
	cout << (((num[0]*num[0])%mo)*num[0])%mo << endl;
}
