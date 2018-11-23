#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair

using namespace std;

typedef pair<int, int> pie;
long double pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286;
int n, x, y;
vector<pie> points;
long double maxr = 0, minr = 1e9;
long double maxrd = 0, minrd = 1e9;


int main()
{
	cout.precision(20);
	cout << fixed;
	cin >> n >> x >> y;
	for(int i = 0; i < n; i++)
	{
		int tempx, tempy;
		scanf("%d %d", &tempx, &tempy);
		long double temp = sqrt((tempx - x) * (tempx- x) + (tempy - y) * (tempy - y));
		if((long long)temp < minr)
		{
			minr = (long long)temp;
			minrd = temp - minr;
		}
		else
		{
			if((long long)temp == minr)
			{
				if(minrd > temp - minr)
					minrd = temp - minr;
			}
		}
		if((long long)temp > maxr)
		{
			maxr = (long long)temp;
			maxrd = temp - maxr;
		}
		else
		{
			if((long long)temp == maxr)
			{
				if(maxrd < temp - maxr)
					maxrd = temp - maxr;
			}
		}
	}
	long long ans = maxr * maxr - minr * minr;
	cout << pi *((long double)(maxr + maxrd) *  (long double)(maxr + maxrd) - (long double)(minr + minrd) * (long double)(minr + minrd)) << endl;


}

