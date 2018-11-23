#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

int n = 1e5;
int maxnum = 1e9;

int main()
{
	srand(time(NULL));
	cout << n << endl;
	for(int i = 0; i < n; i++)
		cout << rand()%(maxnum - 1) + 1 << " ";
}
