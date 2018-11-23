#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

vector<pie> mv;
int n;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		int co = temp;
		while(!mv.empty() && mv[mv.size() - 1].F > temp)
		{
			co = max(co, mv[mv.size() - 1].F);
			mv.pop_back();
		}
		mv.push_back(mp(co, temp));
	}
	cout << mv.size() << endl;
}
