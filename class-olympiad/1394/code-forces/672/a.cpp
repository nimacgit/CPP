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
int rev(int a)
{
	int b = 0;
	while(a)
	{
		b = b*10 + a % 10;
		a /= 10;
	}
	return b;
}

string s;


int main()
{
	cin >> n;
	for(int i = 1; i < 10000; i++)
	{
		int temp =  rev(i);
		while(temp)
		{
			s += (temp % 10) + '0';
			if(s.length() == n)
			{
				cout << s[n - 1] << endl;
				return 0;
			}
			temp /= 10;
		}
		temp = i;
		while(temp % 10 == 0 && temp > 0)
		{
			s += '0';
			if(s.length() == n)
			{
				cout << 0 << endl;
				return 0;
			}
			temp /= 10;

		}
	}
}
