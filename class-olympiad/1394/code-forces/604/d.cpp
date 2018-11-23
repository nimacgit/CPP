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
const int maxn = 1000 * 1000;
long long p, k;
vector<int> selfi;
int usi[maxn + 100];
const long long mo = long long(1000000007);


int main()
{
	cin >> p >> k;
	for(int i = 0; i < p; i++)
	{
		long long temp =(long long)(i * k) % p;
		if(temp == i)
			selfi.push_back(i);
		usi[temp]++;
	}
	long long difi = 1;
	long long ans = 0;
	for(int i = 0; i < p; i++)
		difi *= usi[i];
	int tempo = 1;
	for(int i = 0; i < selfi.size(); i++)
		tempo = (tempo * selfi.size()) % mo;
	ans = 1;
	for(int i = 0; i < p; i++)
		if(usi[i] != 0)
		{
			
		}
		
		
}
