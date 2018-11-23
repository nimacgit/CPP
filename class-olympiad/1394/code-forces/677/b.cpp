#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

long long n, h, k;



int main()
{
	long long temp;
	cin >> n >> h >> k;
	long long remain = 0, t = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> temp;
		if(remain + temp > h)
		{
			long long s = remain + temp - h;
			t += (s + k - 1) / k;
			remain = max((long long)0, remain - ((s+k-1)/k)*k);
		}
		remain += temp;
	}
	if(remain != 0)
		t += (remain + k - 1) / k;
	cout << t << endl;

}
