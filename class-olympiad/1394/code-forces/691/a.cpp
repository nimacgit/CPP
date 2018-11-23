#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

int n, co = 0;


int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		co += temp;
	}
	if(n == 1)
	{
		if(co == 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		return 0;
	}
	if(co == n - 1)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}
