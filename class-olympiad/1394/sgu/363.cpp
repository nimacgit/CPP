#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <list>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <deque>
#include <map>

using namespace std;

const int maxn = 100;
int m, n;
int moment[maxn + 10], servtime[maxn + 10], fintime[maxn + 10], fque[maxn + 10];
deque < pair<int, int> > window[maxn + 10];

int minim()
{
	int pos = 0;
	for(int i = 1; i < m; i++)
		if(window[i].size() < window[pos].size())
			pos = i;
	return pos;
}


int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		scanf("%d %d", &moment[i], &servtime[i]);
	}
	int posperson = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			while(!window[j].empty() && window[j][0].second <= moment[i])
			{
				fintime[window[j][0].first] = window[j][0].second;
				//cerr << " setfintime " << window[j][0].first << "  " << fintime[window[j][0].first] << "   " << window[j][0].second << endl;
				window[j].pop_front();
			}
		}
		int pos = minim();
		//cerr << i << "  " << pos << "  " << window[pos].size() << endl;
		if(!window[pos].empty())
			window[pos].push_back(make_pair(i,servtime[i] + window[pos].back().second));
		else
			window[pos].push_back(make_pair(i,moment[i] + servtime[i]));
		fque[i] = pos;
	}
	for(int j = 0; j < m; j++)
	{
		while(!window[j].empty())
		{
			fintime[window[j][0].first] = window[j][0].second;
			//cerr << " setfintime " << window[j][0].first << "  " << fintime[window[j][0].first] << "   " << window[j][0].second << endl;
			window[j].pop_front();
		}
	}
	for(int i = 0; i < n; i++)
		cout << fque[i] + 1 << " " << fintime[i] << endl;

	
}