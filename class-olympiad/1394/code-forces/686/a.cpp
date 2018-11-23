#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

long long n, x, r = 0;
char c;

int main()
{
	cin >> n >> x;
	for(int i = 0, d; i < n; i++)
	{
		cin >> c >> d;
		if(c == '+')
			x += d;
		else
		{
			if(d <= x)
				x -= d;
			else
				r++;
		}
	}
	cout << x << " " << r << endl;
}
