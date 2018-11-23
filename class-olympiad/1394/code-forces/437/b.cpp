#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

const int maxn = 40;
vector<int> t[maxn + 10];
long long two[maxn + 10];
long long sum , lim;
vector<int> ans;

void pre()
{
	two[0] = 1;
	for(int i = 1; i < maxn; i++)
		two[i] = two[i - 1] * 2;
}

void ad(long long a)
{
	int pos = 0;
	for(int i = 0; i < maxn && (a % two[i]) == 0; i++)
			pos = i;
	t[pos].push_back(a);
}

int main()
{
	pre();
	cin >> sum >> lim;
	for(int i = 0; i < lim; i++)
		ad(i + 1);
	long long x = 0;
	for(int i = maxn; i >= 0; i--)
	{
		while(two[i] + x <= sum && t[i].size() > 0)
		{
			x += two[i];
			ans.push_back(t[i].back());
			t[i].pop_back();
		}
	}
	if(x == sum)
	{
		cout << ans.size() << endl;
		for(int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
		cout << endl;
	}
	else
		cout << -1 << endl;
}
