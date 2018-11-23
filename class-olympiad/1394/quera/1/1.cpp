#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

const int maxn = 1e5;
bool seen[30];
int n;
string s;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	int m = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> s;
		memset(seen, 0, sizeof seen);
		int co = 0;
		for(int j = 0; j < s.length(); j++)
			if(!seen[s[j]-'a'])
			{
				seen[s[j] - 'a'] = true;
				co++;
			}
		m = max(m, co);
	}
	cout << m << endl;
}
