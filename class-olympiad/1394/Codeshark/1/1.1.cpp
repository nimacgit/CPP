#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

const int maxn = 1e8;
int mo = 12373;
int n = 1111151;
int d[maxn];


int main()
{
	long long sum = 0;
	for(int i = 1; i < n; i++)
	{
		long long l = i;
		long long k = 1;
		while(l != 1 && l > 1)
		{
			k++;
			l = (l*i)%n;
		}
		sum =(sum + k)%mo;
	}
	cout << sum << endl;


	
	
}
