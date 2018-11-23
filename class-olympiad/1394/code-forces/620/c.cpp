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
const int maxn = 300 * 1000;
int n;
vector <pie> myvec;
set <int> myset;

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		int temp;
		scanf("%d", &temp);
		if(myset.find(temp) != myset.end())
		{
			myvec.push_back(mp(i + 1 - myset.size(),i + 1));
			myset.clear();
		}
		else
			myset.insert(temp);
	}
	if(myvec.size() != 0)
	{
		myvec[myvec.size() - 1].second = n;
		cout << myvec.size() << endl;
	}
	else
	{
		cout << -1 << endl;
		return 0;
	}
	for(int i = 0; i < myvec.size(); i++)
		cout << myvec[i].first << " " << myvec[i].second << endl;

}

