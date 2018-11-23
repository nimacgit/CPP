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


const int maxn = 500;
int n, m, x , y;
bool mark[maxn + 100][maxn + 100];
string s;

int main()
{
	cin >> n >> m >> x >> y;
	cin >> s;
	x--;y--;
	for(int i = 0; i < s.length(); i++)
	{
		if(!mark[x][y])
		{
			cout << 1 << " ";
			mark[x][y] = true;
		}
		else
			cout << 0 << " ";
		if(s[i] == 'U')
		{

			if(x > 0)
				x--;
		}
		else if(s[i] == 'D')
		{
			if(x < n - 1)
				x++;
		}
		else if(s[i] == 'L')
		{

			if(y > 0)
				y--;
		}
		else if(y < m - 1)
			y++;
	}
	int sum = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(!mark[i][j])
				sum++;
	cout << sum << endl;


}	
