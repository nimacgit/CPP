#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second
using namespace std;

typedef pair<int, int> pie;
const int maxn = 5 * 1000 + 100;
pie r[maxn], c[maxn];
int n, m ,k;

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 0,temp1, temp2, temp3; i < k; i++)
	{
		scanf("%d %d %d", &temp1, &temp2, &temp3);
		if(temp1 == 1)
			r[temp2 - 1] = mp(temp3, i + 1);
		else
			c[temp2 - 1] = mp(temp3, i + 1);
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(r[i].S > c[j].S)
				printf("%d ", r[i].F);
			else
				printf("%d ", c[j].F);
		}
		printf("\n");
	}
}	
