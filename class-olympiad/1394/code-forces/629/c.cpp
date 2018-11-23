#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second
using namespace std;

typedef pair<int, int> pie;
const int maxn = 1000;
int n, m, o, c;
string s;
int mod = 1e9 + 7;
int main()
{
	cin >> n >> m;
	cin >> s;
	if(n % 2 != 0)
	{
		cout << 0 << endl;
		return 0;
	}
	for(int i = 0; i < m; i++)
	{
		if(s[i] == '(')
			o++;
		else
			c++;
	}
	if(abs(o - c) > n - m)
	{
		cout << 0 << endl;
		return 0;
	}
	if(abs(o - c) == n - m)
	{
		cout << 1 << endl;
		return 0;
	}


}
