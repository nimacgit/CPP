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
int lim = 1e9 + 7;
set<pie> fact;
set<pie>::iterator it;


int main()
{
	int m;
	cin >> m;
	long long num = 1;
	for(int i = 0; i < m; i++)
	{
		int pr;
		scanf("%d", &pr);
		num = (num * pr) % lim;
		it = fact.lower_bound(mp(pr, 0));
		if(it >= fact.end())
			fact.insert(mp(pr, 1));
		else
		{
			if(it->first == pr)
			{
				int co = it->second + 1;
				fact.erase(it);
				fact.insert(mp(pr, co));
			}
			else
			{
				fact.insert(mp(pr, 1));
			}
		}
	}
	int con = 1;
	while(!fact.empty())
	{
		int tem = fact.begin()->second + 1;
		con = (con =tem;
	}
}
