#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

int n;
int x[4], y[4];

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> x[i] >> y[i];
	if(n == 1)
	{
		cout << -1 << endl;
		return 0;
	}
	if(n == 2)
	{
		if(x[0] == x[1] || y[0] == y[1])
			cout << -1 << endl;
		else
			cout << abs(x[1] - x[0]) * abs(y[1] - y[0]) << endl;
		return 0;
	}
	if(n == 3 || n == 4)
	{
		int x1,y1,y2,x2;
		bool isok = false;
		for(int i = 0;!isok && i < 3; i++)
		{
			for(int j = i + 1; j < 3 && !isok; j++)
			{
				if(x[i] != x[j] && y[i] != y[j])
				{
					x1 = x[i], x2 = x[j], y1 = y[i], y2 = y[j];
					isok = true;
				}
			}
		}
		cout << abs(x1 - x2) * abs(y1 - y2) << endl;
	}
}
