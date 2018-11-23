#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

int n, a, b, c;

int main()
{
	cin >> n;
	c = 0;
	b = 0;
	a = 5;
	for(int i = 0, temp; i < n; i++)
	{
		cin >> temp;
		if(temp == 5)
		{
			b++;	
		}
		else
		{
			b++;
			c--;
		}
	}
	cout << 5 << " ";
	cout << b << " ";
	cout << c << endl;
}
