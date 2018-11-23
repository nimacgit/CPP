#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

int n, v;
vector<int> f, s;
const int maxn = 1e4;
int a[maxn];
long long sum;
int main()
{
	cin >> n >> v;
	for(int i = 0 , temp1, temp2; i < n; i++)
	{
		cin >> temp1 >> temp2;
		a[temp1] += temp2;
	}
	int rem = v;
	for(int i = 0; i < maxn; i++)
	{
		rem = min(v, rem + v);
		int g = min(a[i], rem + v);
		rem -= g;
		sum += g;
	}
	cout << sum << endl;
}
