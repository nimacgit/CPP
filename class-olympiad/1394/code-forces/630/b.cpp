#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

long double mul = 1.000000011;
long double ans;
int t;

long double gt(long double temp, int t)
{
	if(t % 2 == 0)
	{
		if(t > 0)
		{
			long double te = gt(temp, t / 2);
			return te * te;
		}
		else
			return 1;
	}
	else
	{
		long double te = gt(temp, t / 2);
		return te * te * temp;
	}
}


int main()
{
	cout << setprecision(40);
	cin >> ans >> t;
	cout << ans * gt(mul, t) << endl;
}
