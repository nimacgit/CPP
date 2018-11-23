#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

long double n, v1, v2, l, k;


bool isok(long double t)
{
	p = 1;
	long double num = n;
	while(num > 0)
	{
		num = max(0.0, num - k);
		double pos = getpos(t, l - p);
		t -= 
	}
}


int main()
{
	cin >> n >> l >> v1 >> v2 >> k;
	long double s = 0, e = l / v1;
	int i = 100;
	while(i > 0)
	{
		long double mid = (s + e) / 2l
		if(isok(mid))
			e = mid;
		else
			s = mid;
		i--;
	}
	
}
