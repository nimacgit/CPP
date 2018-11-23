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
int maxn = 17171717;
const int delta = 648481;

int main()
{
	long long a = 0;
	long long b = 1;
	for(int i = 1; i < maxn; i++)
	{
		long long c = (a + b)%delta;
		a = b; 
		b = c;
	}
	cout << b << endl;
	cout << ((b-1)*(b - 2) ) % delta << endl;
}
