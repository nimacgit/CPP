#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <deque>
#include <set>

using namespace std;

const int maxn = 3 * 1000 * 1000;
deque < pair<int,int> > mindec, maxdec;
int a[maxn + 100];
int n, t, maxcon = 1, start = 0;

int abs(int a)
{
	if(a < 0)
		return -1 * a;
	return a;
}


int main()
{
	std::ios::sync_with_stdio(false);
	cin >> t >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	mindec.push_back(make_pair(a[0], 0));
	maxdec.push_back(make_pair(a[0], 0));
	for(int i = 1; i < n; i++)
	{
		while(maxdec.size() > 0 && abs(a[i] - maxdec.front().first) > t)
		{
			start = max(start, maxdec.front().second + 1);
			maxdec.pop_front();
		}
		if(maxdec.size() > 0 && a[i] >= maxdec.front().first)
		{
			maxdec.clear();
			maxdec.push_back(make_pair(a[i],i));
		}
		else
		{
			while(maxdec.size() > 0 && maxdec.back().first <= a[i])
				maxdec.pop_back();
			maxdec.push_back(make_pair(a[i], i));
		}
		while(mindec.size() > 0 && abs(a[i] - mindec.front().first) > t)
		{
			start = max(start, mindec.front().second + 1);
			mindec.pop_front();
		}
		if(mindec.size() > 0 && a[i] <= mindec.front().first)
		{
			mindec.clear();
			mindec.push_back(make_pair(a[i],i));
		}
		else
		{
			while(mindec.size() > 0 && mindec.back().first >= a[i])
				mindec.pop_back();
			mindec.push_back(make_pair(a[i], i));
		}
		maxcon = max(maxcon, i - start + 1);
	}
	cout << maxcon << endl;
}