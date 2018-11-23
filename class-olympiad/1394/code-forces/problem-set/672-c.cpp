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
int n;
int a[maxn];
map <long long, int> mymap;



int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	long long sum = 0;
	int ind = 0;
	for(int i = 0; i < n; i++)
	{
		sum += a[i];
		mymap[sum]++;
		ind = max(mymap[sum], ind);
	}
	cout << n - ind << endl;
}
