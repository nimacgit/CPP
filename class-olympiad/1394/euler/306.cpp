#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;
const int maxn = 50;
bool fwin[maxn + 100];
long long co = 3;

int main()
{
	fwin[0] = false;
	fwin[1] = false;
	fwin[2] = true;
	fwin[3] = true;
	fwin[4] = true;
	for(int i = 5; i <= maxn; i++)
	{
		bool flag = false;
		for(int j = 0; !flag && j < i - 1; j++)
			flag = flag || (!(fwin[j] ^ fwin[i - 2 - j]));
		cerr << flag << endl;
		fwin[i] = flag;
		if(flag)
			co++;
	}
	cout << co << endl;
}
