#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

const int maxn = 1000;
int n, m;
string s;

char c(int a)
{
	if(a)
		return 'B';
	return 'W';
}

int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		cin >> s;
		for(int j = 0; j < m; j++)
		{
			if(s[j] != '-')
				cout << c((i + j) % 2);
			else
				cout << '-';
		}
		cout << endl;
	}
}
