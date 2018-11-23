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
long long n;
int a[maxn + 1000];
long long sum = 0;
long long mini = 1e9 + 2;


int abs(int b)
{
	if( b < 0)
		return -1 * b;
	return b;
}

int main()
{
	cin >> n;	
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		if(a[i] < mini)
			mini = a[i];
	}
	long long maxl = 0, l = 0, check = 0, co = 0;
	while(a[co] != mini && co < n)
	{
		co++;
		check++;
	}
	co = n - 1;
	while(a[co] != mini && co >= 0)
	{
		co--;
		check++;
	}
	for(int i = 0; i < n; i++)
	{
		if(a[i] == mini)
		{
			maxl = max(l, maxl);
			l = 0;
		}
		else
			l++;
			
	}
	maxl = max(maxl, l);
	maxl = max(maxl, check);
	cout << (long long)mini * (long long)n + (long long)maxl << endl;


}	
