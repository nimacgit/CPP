#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

const int maxn = 1e6;
int n, d;
long long s = 0;
int a[maxn];

long long check(long long num)
{
	int co = 0, bco = 0;

	while(num > 0)
	{	
		a[co] = num % 2;
		co++;
		num /= 2;
	}
	long long sum = 0;
	for(int i = 0; i < d; i++)
		sum += a[i];
	if(sum % 2 == 1)
		return 0;
	for(int i = 1; i < n - d; i++)
	{
		sum -= a[i - 1];
		sum += a[i + d];
		if(sum % 2 == 1)
			return 0;
	}
	return 1;

}


int main()
{
	cin >> n >> d; 
	for(int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		s *= 2;
		if(temp % 2 == 1)
			s++;
	}
	int mini = 1e9;
	for(long long i = 0; i < (1<<n); i++)
	{
		long long temp = s ^ i;
		if(check(temp))
		mini = min(mini, __builtin_popcount(i));
	}
	cout << mini << endl;
}
