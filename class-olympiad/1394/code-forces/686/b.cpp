#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

const int maxn = 1000;
long long n;
int a[maxn];

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n - 1; j++)
		{
			if(a[j] > a[j + 1])
			{
				cout << j + 1 << " " << j + 2 << endl;
				swap(a[j], a[j + 1]);
			}
		}
	}
	cerr << endl;
}
