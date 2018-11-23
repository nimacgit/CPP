#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

long long x[3], y[3];
long long ansx, ansy;

int main()
{
	for(int i = 0; i < 3; i++)
		cin >> x[i] >> y[i];
	if(x[0] == x[1])
	{
		ansx = x[2];
	}
	else if(x[0] == x[2])
	{
		ansx = x[1];
	}
	else if(x[2] == x[1])
	{
		ansx = x[0];
	}
	if(y[0] == y[1])
		ansy = y[2];
	else if(y[0] == y[2])
		ansy = y[1];
	else
		ansy = y[0];
	cout << ansx << " " << ansy << endl;
}
