#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

long long p, q, co;

int main()
{
	cin >> p >> q;
	while(p > 1 && q > 1)
	{
		if(p > q)
			swap(p, q);
		co += q / p;
		q %= p;
	}
	co += max(p, q);
	cout << co << endl;
}
