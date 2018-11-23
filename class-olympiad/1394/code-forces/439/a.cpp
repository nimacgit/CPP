#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

const int maxn = 200;
int n, d, co, pos;
int t[maxn];

int main()
{
	cin >> n >> d;
	for(int i = 0; i < n; i++)
		cin >> t[i];
	if(t[0] > d)
	{
		cout << -1 << endl;
		return 0;
	}
	pos = t[0];
	co = 0;
	for(int i = 1; i < n; i++)
	{
		pos += 10;
		co += 2;
		pos += t[i];
		if(pos > d)
		{
			cout << -1 << endl;
			return 0;
		}
	}
	co += (d - pos) / 5;
	cout << co << endl;
}
