#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair

using namespace std;

typedef pair<int, int> pie;

int n;

int find(int a, int b)
{
	if(b == 1)
		return a - 1;
	if(a == b)
		return 1000 * 1000;
	int co = 0;
	co += (a-b)/b;
	a -= co * b;
	if(a > b)
	{
		co++;
		a -= b;
	}
	return co + find(b, a);
}

int main()
{
	cin >> n;
	int mini = 1000 * 1000;
	if(n == 1)
	{
		cout << 0 << endl;
		return 0;
	}
	for(int i = n-1; i >= n/2; i--)
		mini = min(mini,find(n, i));
	cout << mini << endl;
}
