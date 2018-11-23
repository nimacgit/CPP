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


const int maxn = 1000 * 100;
int n, k;
int a[maxn + 100];
int maxi = 0;

int main()
{
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	maxi = a[n - 1];
	while(n < 2 * k)
	{
		n--;
		k--;
	}
	for(int i = 0; i < n / 2; i++)
		maxi = max(a[i] + a[n - i - 1], maxi);
	cout << maxi << endl;


}	
