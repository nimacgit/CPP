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


int n, m;
int a[200][200];
long long maxi = 0;

int abs(int b)
{
	if( b < 0)
		return -1 * b;
	return b;
}

int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		int mini = 1e9 + 7;
		int temp;
		for(int j = 0; j < m; j++)
		{
			scanf("%d", &temp);
			if(temp < mini)
				mini = temp;
		}
		if(mini > maxi)
			maxi = mini;
	}
	cout << maxi << endl;


}	
