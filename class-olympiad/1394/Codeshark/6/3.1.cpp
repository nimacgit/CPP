#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;
const int maxn = 1e8;
bool notp[maxn];
vector<int> mv;

void sieve()
{
	for(int i = 2; i < maxn; i++)
		if(!notp[i])
		{
			mv.push_back(i);
			for(int j = 2; i * j < maxn; j++)
				notp[i * j] = true;
		}
}


int main()
{
	sieve();
	for(int )
}
