#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<long long, long long> pie;
const int maxn = 2e5;
const long long inf = 1e9;
vector<pie> mv;
long long n;
long long co = 0;
vector<pie>::iterator it;
int main()
{
	cin >> n;
	ios::sync_with_stdio(false);
	for(int i = 0; i < n; i++)
	{
		long long temp;
		cin >> temp;
		mv.push_back(mp(temp, i));
	}
	sort(mv.begin(), mv.end());
	for(long long i = 0; i < 32; i++)
	{
		for(int j = 0; j < mv.size(); j++)
		{
			it = upper_bound(mv.begin(), mv.end(), mp((1ll<<i) - mv[j].F, inf));
			if(it != mv.begin())
			{
				
				it--;
				while(it != mv.begin() && it->F == ((1ll<<i) - mv[j].F))
				{
					if(it->S < mv[j].S)
						co++;
					it--;
				}
				if(it->F == ((1ll<<i) - mv[j].F) && it->S < mv[j].S)
					co++;
			}
		}
	}
	cout << co << endl;
}
