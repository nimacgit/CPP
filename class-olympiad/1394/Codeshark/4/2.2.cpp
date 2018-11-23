#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

int mo = 55117;
int n = 1002;
int m = 123457;

int main()
{
	int s = 2016 % m;
	cout << s << " ";
	for(int i = 0; i < n; i++)
	{
		s = (s * 1437 + 1395) % m;
		cout << s << " ";
	}
	cout << endl;
}
