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
int a[1000];
int m, k;
int mx = 0;

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		if(a[i] == 1)
			m = i;
		if(a[i] == n)
			k = i;
	}
	mx = abs(m - k);
	if(k > m)
		swap(m ,k);
	mx = max(mx, max(n - k - 1, m));
	cout << mx << endl;
}
