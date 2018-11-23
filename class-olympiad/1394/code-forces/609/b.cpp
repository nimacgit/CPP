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


const int maxn = 500;
int n, m;
int a[maxn];


int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		int temp;
		scanf("%d", &temp);
		temp--;
		a[temp]++;
	}
	long long sum = 0;
	for(int i = 0; i < m; i++)
	{
		for(int j = i + 1; j < m; j++)
			sum += a[i] * a[j];
	}
	cout << sum << endl;

}	
