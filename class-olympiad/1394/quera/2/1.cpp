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
const int maxn = 1e5;
int a[maxn];
long long sum = 0;


int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i], sum += a[i];
	long long mid = sum / n;
	long long ans = 0;
	for(int i = 0; i < n; i++)
		ans += max((long long)0,a[i] - mid);
	cout << ans << endl;
}
