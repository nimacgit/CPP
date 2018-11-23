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

const int maxn = 20;
long long sumx = 0, sumy = 0;
int x, y, bx, by;
int arrx[maxn], arry[maxn];
int main()
{
	cin >> x >> bx;
	long long pos = 1;
	for(int i = 0; i < x; i++)
		cin >> arrx[i];
	for(int i = x - 1; i >= 0; i--)
	{
		sumx += pos * arrx[i];
		pos *= bx;
	}
	cin >> y >> by;
	pos = 1;
	for(int i = 0; i < y; i++)
	{
		cin >> arry[i];
	}
	for(int i = y - 1; i >= 0; i--)
	{
		sumy += pos * arry[i];
		pos *= by;
	}
	if(sumx < sumy)
	{
		cout << '<' << endl;
	}
	else if(sumx == sumy)
	{
		cout << '=' << endl;
	}
	else cout << '>' << endl;
}
