#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

int co = 0, n;

int main()
{
	cin >> n;
	int ltemp = 8;
	for(int i = 0, temp; i < n; i++)
	{
		cin >> temp;
		if(ltemp != temp)
			co++;
		ltemp = temp;
	}
	cout << co << endl;
}
