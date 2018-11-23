#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

vector<int> ans;
int n, k, v;



int main()
{
	cin >> n >> v;
	for(int i = 0, temp; i < n; i++)
	{
		cin >> k;
		bool flag = false;
		for(int j = 0; j < k; j++)
		{
			cin >> temp;
			if(v > temp)
				flag = true;
		}
		if(flag)
			ans.push_back(i);
	}
	cout << ans.size() << endl;
	for(auto u : ans)
		cout << u + 1 << " ";
	cout << endl;
}
