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
const int maxn = 2e5;
int a[maxn];
int co = 1, maxi = 0;

int main()
{
	cin >> n;
	cin >> a[0];
	for(int i = 1; i < n; i++)
	{
		cin >> a[1];
		if(a[1] > a[0])
			co++;
		else
		{
			maxi = max(co, maxi);
			co = 1;
		}
		a[0] = a[1];
	}
	maxi = max(maxi, co);
	cout << maxi << endl;
		
}
