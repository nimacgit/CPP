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

int delta = 648481;
long long pos = (long long)1e17 + 17;
long long fin = (long long)1e17 + (long long)1717171;
const int maxn = 1e7;
bool notp[maxn + 100];

void init()
{

	for(long long i = 2; i * i <= fin; i++)
	{
		long long st = pos/i;
		st *= i;
		if(st < pos)
			st+=i;
		for(long long j = st; j <= fin; j+=i)
			notp[j - pos] = true;
	}
}

int main()
{
	init();
	long long sum = 1, co = 0;
	for(int i = 0; i <= fin-pos; i++)
	{
		if(!notp[i])
			co++;
	}
	for(int i = 0; i < 17; i++)
		sum = (sum * co) % delta;
	cout << sum << endl;
}
