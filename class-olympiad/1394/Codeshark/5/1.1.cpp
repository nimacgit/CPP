#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

int mo = 62137;
const int maxn = 1e7;
int main()
{
	long long sum = 0;
	for(int i = 2; i <= maxn; i++)
	{
		for(long long j = i - 1; j >= 1; j--)
			if((j * j) % i == j)
			{
				sum += j;
				j = 0;
				sum %= mo;
			}
	}
	cout << sum << endl;
}
