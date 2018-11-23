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
const int maxn = 5 * 1000;
bool a[maxn + 100];
int n, co = 0;


int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int temp;
		scanf("%d", &temp);
		if(a[temp])
			co++;
		else
			if(temp > n)
				co++;
			else
				a[temp] = true;
	}
	cout << co << endl;
}
