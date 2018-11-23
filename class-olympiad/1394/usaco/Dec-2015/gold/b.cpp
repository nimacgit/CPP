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

const int maxn = 1000 * 1000 * 10;
bool can[maxn];
int a, b, t;

int main()
{
	ifstream in("feast.in", ios::in);
	in >> t >> a >> b;
	can[0] = true; 
	for(int i = min(a, b); i <= t; i++)
	{
		if(i - max(a, b) >= 0)
			can[i] = can[i - b] | can[i - a];
		else
			can[i] = can[i - min(a, b)];
	}
	for(int i = 0; i <= t / 2; i++)
		can[i] = can[i] | can[2 * i] | can[2 * i + 1];
	for(int i = min(a, b); i <= t ; i++)
	{
		if(i - max(a, b) >= 0)
			can[i] = can[i] | can[i - b] | can[i - a];
		else
			can[i] = can[i] | can[i - min(a, b)];
	}
	ofstream out("feast.out", ios::out);
	for(int i = t; i >= 0; i--)
	{
		if(can[i])
		{
			out << i << endl;
			return 0;
		}
	}

}
