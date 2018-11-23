#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;
int n, m, k;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	int x = 0, y = 0;
	int next = 1;
	for(int i = 0; i < k - 1; i++)
	{
		cout << 2 << " " << y + 1 << " " << x + 1;
		x += next;
		if(x == -1)
		{
			next *= -1;
			x++;
			y++;
		}
		if(x == m)
		{
			next *= -1;
			x--;
			y++;
		}
		cout << " " << y + 1 << " " << x + 1 << endl;
		x+=next;
		if(x == -1)
		{
			next *= -1;
			x++;
			y++;
		}
		if(x == m)
		{
			next *= -1;
			x--;
			y++;
		}
	}
	cout  << n * m - 2 * (k - 1) << " ";
	while(y < n)
	{
		cout << y + 1 << " " << x + 1 << " ";
		x += next;
		if(x == -1)
		{
			next *= -1;
			x++;
			y++;
		}
		if(x == m)
		{
			next *= -1;
			x--;
			y++;
		}
	}
	cout << endl;
}
