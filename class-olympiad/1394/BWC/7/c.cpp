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

const int maxn = 1000 + 100;
string s;
int d[maxn][maxn];

int main()
{
	cin >> s;
	for(int i = 0; i < s.length(); i++)
	{
		d[i][i] = 1;
		for(int j = i - 1; j >= 0 ; j--)
		{
			d[j][i] = max(d[j + 1][i], d[j][i - 1]);
			if(s[i] == s[j])
				d[j][i] = max(d[j][i], d[j + 1][i - 1] + 2);
		}
	}
	cout << s.length() - d[0][s.length() - 1] << endl;
}
