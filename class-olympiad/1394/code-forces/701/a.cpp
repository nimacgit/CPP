#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;
long long sum, n;
vector<pie> mv;

int main()
{
	cin >> n;
	for(int i = 0, temp; i < n; i++)
	{
		cin >> temp;
		sum += temp;
		mv.push_back(mp(temp, i));
	}
	sum *= 2;
	sum /= n;
	int temp;
	while(!mv.empty())
	{
		cout << mv[0].S + 1 << " ";
		temp = mv[0].F;
		swap(mv[0], mv[mv.size() - 1]);
		mv.pop_back();
		for(int i = 0; i < mv.size(); i++)
		{
			if(temp + mv[i].F == sum)
			{
				cout << mv[i].S + 1 << endl;
				swap(mv[i], mv[mv.size() - 1]);
				mv.pop_back();
				i = mv.size();
			}
		}
	}
}
