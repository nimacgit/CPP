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
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		sum += a[i];
	}
	int co;
	int ne = 0;
	co = sum % n;
	sum /= n;
	for(int i = 0; i < n; i++)
		if(a[i] > sum)
		{
			if(co > 0)
			{
				co--;
				ne += a[i] - sum - 1;
			}
			else
				ne += a[i] - sum;
		}
	cout << ne << endl;
}

