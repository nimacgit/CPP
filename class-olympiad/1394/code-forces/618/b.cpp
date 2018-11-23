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
const int maxn = 60;
int a[maxn][maxn];
int n;
int p[maxn];
bool test[maxn][maxn];
bool flag;
bool setlas = false;

int main()
{
	cin >> n;
	for(int i = 0 ; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
				a[i][j]--;
		}
	for(int i = 0; i < n; i++)
	{
		flag = false;
		for(int j = 0; j < n; j++)
			if(!test[i][a[i][j]])
				test[i][a[i][j]] = true;
			else
			{
				flag = true;
				p[i] = a[i][j];
				j = n + 2;
			}
		if(!flag)
		{
			if(!setlas)
			{
				p[i] = n - 1;
				setlas = true;
			}
			else
				p[i] = n - 2;
		}
	}
	for(int i = 0; i < n; i++)
		printf("%d ", p[i] + 1);
	cout << endl;

}	
