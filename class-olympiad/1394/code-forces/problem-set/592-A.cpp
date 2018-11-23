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

int w[8][8], b[8][8];
string s;
char c;

int ans(int p[8][8])
{
	int mini = 100;
	for(int i = 0; i < 8; i++)
	{
		int j;
		for(j = 0; j < 8 && p[j][i] == 0; j++);
		if(j < 8)
			if(p[j][i] == 1)
				mini = min(mini, j);
	}
	return mini;

}

int main()
{
	for(int i = 0; i < 8; i++)
	{
		cin >> s;
		for(int j = 0; j < 8; j++)
		{
			c = s[j];		
			if(c == 'W')
			{
				w[i][j] = 1;
				b[7 - i][7 - j] = -1;
			}
			else if(c == 'B')
			{
				w[i][j] = -1;
				b[7 - i][7 - j] = 1;
			}
			else
				w[i][j] = b[7 - i][7 - j] = 0;
		}
	}
	cerr << ans(w) << " " << ans(b) << endl;
	cout << (ans(w) <= ans(b) ? 'A' : ('B')) << endl;
}
