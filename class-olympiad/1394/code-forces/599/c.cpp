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

const int maxn = 1000 * 100;
int n;
pie sora[maxn + 100];
int lpos = 0;
bool seen[maxn + 100];
bool comp(pie a, pie b)
{
	if(a.first < b.first)
		return true;
	else
	{
		if(a.first == b.first)
			return a.second < b.second;
		else
			return false;
	}
}


int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int temp;
		scanf("%d" , &temp);
		sora[i] = mp(temp, i);
	}
	sort(sora, sora + n, comp);
	int co = 0;
	for(int i = 0; i < n; i++)
	{
		seen[sora[i].second] = true;
		while(lpos < n && seen[lpos])
			lpos++;
		if(lpos > i || lpos == n)
		{
			co++;
		}
	}
	cout << co << endl;
}
