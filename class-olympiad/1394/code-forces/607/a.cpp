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

const int maxn = 1000;
int n, s;
int a[maxn + 100];

int main()
{
	cin >> n >> s;
	for(int i = 0; i < n; i++)
	{
		int temp, val;
		scanf("%d %d", &temp, &val);
		a[temp] = max(a[temp], val);
	}
	int tim = 0;
	for(int i = s; i >= 0; i--)
	{
		if(a[i] > tim)
			tim = a[i];
		tim++;
	}
	tim--;
	cout << tim << endl;
	
}
