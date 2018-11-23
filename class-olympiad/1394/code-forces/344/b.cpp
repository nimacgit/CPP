#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;
int a, b, c, mid;


int main()
{
	cin >> a >> b >> c;
	if((a + b + c) % 2)
	{
		cout << "Impossible" << endl;
		return 0;
	}
	mid = (b + c - a) / 2;
	if(b - mid >= 0 && mid >= 0 && c - mid >= 0)
		cout << b - mid << " " << mid << " " << c - mid << endl;
	else
		cout << "Impossible" << endl;

}
