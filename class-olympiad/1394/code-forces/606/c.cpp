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
int n;
int a[maxn + 100];



int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		a[x] = i;
	}
	int maxim = 1;
	int co = 1;
	for(int i = 1; i < n; i++)
	{
		if(a[i + 1] > a[i])
			co++;
		else
		{
			if(co > maxim)
				maxim = co;
			co = 1;
		}

	}
	if(co > maxim)
		maxim = co;
	cout << n - maxim << endl;
}

