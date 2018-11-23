#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

long long f1 = 1, f2 = 2, f3 = 4, maxn = 10000000000000000;
int mo = 648481;

int main()
{
	for(int i = 4; i <= 1395 * 2016; i++)
	{
		f1 = (f2 + f1 + f3);
		swap(f3, f1);
		swap(f2, f1);
		if(f3 >= maxn)
		{
			cout << i << endl;
			return 0;
		}
	}
	cout << f3 << endl;
}
