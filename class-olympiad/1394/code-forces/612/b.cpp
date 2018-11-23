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


const int maxn = 200 * 1000;
int n;
int a[maxn + 1000];
long long sum = 0;

int abs(int b)
{
	if( b < 0)
		return -1 * b;
	return b;
}

int main()
{
	int lpos;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int temp;
		scanf("%d", &temp);
		temp--;
		a[temp] = i;
	}
	for(int i = 1; i < n; i++)
		sum += abs(a[i] - a[i - 1]);
	cout << sum << endl;


}	
