#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

vector<pie> a[5];
vector<pie> ans;
int n;
bool comp(pie f, pie s)
{
	if(f.F == s.F)
		return f.S < s.S;
	return f.F < s.F;
}
int getans(int x)
{
	int pos[2];
	int posn[2];
	posn[0] = posn[1] = 0;
	for(int i = 0; i < 5; i++)
	{
		pie y = *lower_bound(a[i].begin(), a[i].end(), mp(a[0][x].F, -1), comp);
		if(i == 0)
		{
			pos[0] = y.S;
			posn[0]++;
		}
		else
		{
			if(pos[0] == y.S)
				posn[0]++;
			else
				posn[1]++;
		}
	}
	if(posn[0] == 1)
		return pos[0];
	return pos[1];
}

int main()
{
	cin >> n;
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < n; j++)
		{
			int temp;
			cin >> temp;
			a[i].push_back(mp(temp, j));
		}
		sort(a[i].begin(), a[i].end());
	}
	for(int i = 0; i < n; i++)
		ans.push_back(mp(getans(i), a[0][i].F));
	sort(ans.begin(), ans.end());
	cerr << endl;
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i].S << endl;
}
