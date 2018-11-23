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
const int maxn = 30;
int n;
int a[maxn];

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	reverse(a, a + n);
	long long sum = 0;
	int k = a[0];
	sum += k;
	k--;
	for(int i = 1; i < n && k > 0; i++)
	{
		k = min(a[i], k);
		sum += k;
		k--;
	}
	cout << sum << endl;
}	
