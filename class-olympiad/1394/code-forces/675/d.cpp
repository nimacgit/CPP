#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;
const int maxn = 1000 * 100 + 1000;
set <long long> myset;
int n;
long long a[maxn];
long long m = 1e5;
set<long long>::iterator it, lt, rt;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	myset.insert(a[0] * m);
	for(int i = 1; i < n; i++)
	{
		myset.insert(a[i] * m + i);
		it = myset.find(a[i] * m + i);
		lt = it;
		if(it != myset.begin())
		{
			it--;
			lt = it;
			it++;
		}
		it++;
		rt = it;
		it--;
		if(rt == myset.end())
		{
			cout << (*(lt)) / m << " ";
		}
		else if(it == myset.begin())
		{
			cout << (*(rt)) / m << " ";
		}
		else
		{
			long long l, r;
			r = (*(rt))%m;
			l = (*(lt))%m;
			if(r > l)
			{
				cout << (*(rt)) / m << " ";
			}
			else
			{
				cout << (*(lt)) / m << " ";
			}
		}
	}
	cout << endl;
}
