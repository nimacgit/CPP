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

deque <pie> maxi, mini;
int num[maxn + 100];
int n;
int maxim = 0;

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		scanf("%d", &num[i]);
	int start = 0;
	for(int i = 0; i < n; i++)
	{
		while(!maxi.empty() && num[i] >= maxi.back().first)
			maxi.pop_back();
		maxi.push_back(mp(num[i], i));
		while(!mini.empty() && num[i] <= mini.back().first)
			mini.pop_back();
		mini.push_back(mp(num[i], i));
		while(maxi.front().first - mini.front().first > 1)
		{
			start++;
			while(!maxi.empty() && maxi.front().second < start)
				maxi.pop_front();	
			while(!mini.empty() && mini.front().second < start)
				mini.pop_front();
		}
		if(i - start + 1 > maxim)
			maxim = i - start + 1;

	}
	cout << maxim << endl;
}	
