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

const int maxn = 5;
int n, m;
int a[maxn + 100];

int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	int co = 0;
	int sum = 0;
	for(int i = n - 1;i >= 0 && sum < m; i--)
	{
		co++;
		sum += a[i];
	}
	cout << co << endl;
}
