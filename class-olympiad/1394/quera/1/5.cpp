#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

int x, y;
char c;
map<pie, int> m;
int ans = 0;

int main()
{
	cin >> c;
	cin >> c;
	m[mp(0,0)] = 1;
	ans  = 1;
	while(c != 'K')
	{
		if(c == 'W')
			x--;
		else if(c == 'N')
			y++;
		else if(c == 'S')
			y--;
		else if(c == 'E')
			x++;
		if(!m[mp(x, y)])
		{
			m[mp(x, y)] = 1;
			ans++;
		}
		cin >> c;
	}
	cout << ans << endl;
}
