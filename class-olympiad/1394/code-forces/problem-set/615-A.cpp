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
bool a[maxn + 100];
int n, m;


int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		int temp;
		scanf("%d", &temp);
		for(int j = 0; j < temp; j++)
		{
			int temp2;
			scanf("%d", &temp2);
			a[temp2] = true;
		}
	}
	for(int i = 1; i <= m; i++)
		if(!a[i])
		{
			cout << "NO" << endl;
			return 0;
		}
	cout << "YES" << endl;
}
