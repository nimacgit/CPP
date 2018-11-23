#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

int n, h;
long long sum = 0;

int main()
{
	cin >> n >> h;
	int temp;
	for(int i = 0; i < n; i++)
	{
		cin >> temp;
		if(temp > h)
			sum += 2;
		else
			sum ++;
	}
	cout << sum << endl;
}
