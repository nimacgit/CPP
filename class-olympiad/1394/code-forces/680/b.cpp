#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

int n, a;
int c[1000];


int main()
{
	cin >> n >> a;
	for(int i = 0; i < n; i++)
		cin >> c[i];
	a--;
	int sum = 0;
	if(c[a])
		sum = 1;
	int k;
	for(k = 1; k+a < n && a-k >= 0; k++)
	{
		if(c[a+k] && c[a-k])
			sum+=2;
	}
	if(k + a >= n)
	{
		while(a - k >= 0)
		{
			if(c[a - k])
				sum++;
			k++;
		}
	}
	else
	{
		while(a + k < n)
		{
			if(c[a + k])
				sum++;
			k++;
		}
	}
	cout << sum << endl;
}
