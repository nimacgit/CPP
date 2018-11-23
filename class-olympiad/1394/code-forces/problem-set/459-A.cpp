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

int x[4], y[4];
int abs(int a)
{
	if(a < 0)
		return -1 *a;
	return a;
}

int main()
{
	cin >> x[0] >> y[0] >> x[1] >> y[1];
	if(x[0] == x[1])
	{
		cout  << x[0] + abs(y[0] - y[1]) << " " << y[0] << " " << x[1] + abs(y[0] - y[1]) << " " << y[1] << endl;
		return 0;
	}
	if(y[0] == y[1])
	{
		cout << x[0] << " "  << y[0] + abs(x[0] - x[1]) << " " << x[1] << " " << y[1] + abs(x[0] - x[1]) << endl;
		return 0;
	}
	if(abs(x[0] - x[1]) != abs(y[0] - y[1]))
			cout << -1 << endl;
	else
		cout << x[0] << " " << y[1] << " " << x[1] << " " << y[0] << endl;
		
}
