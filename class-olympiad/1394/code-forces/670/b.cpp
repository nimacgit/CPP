#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

const int maxn = 1e6;
int n, k;
int a[maxn];
long long ans;

int main()
{
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 1; k > 0; i++)
	{
		if(k - i < 0)
			cout << a[k - 1] << endl;
		else if(k == i)
			cout << a[i - 1] << endl;
		k -= i;
	}
}
