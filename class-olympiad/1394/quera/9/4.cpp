#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

const int maxn = 1e6 + 10;
int a[maxn];
int n, d, sum;
int ans[maxn];



int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> d; 
	long long temp;
	for(int i = 0; i < n; i++)
	{
		cin >> temp;
		temp %= 2;
		a[i] = temp;
	}
	for(int i = 0; i < d && i < n; i++)
		sum += a[i];
	if(sum % 2 == 0)
		ans[0] = 0;
	else 
		ans[0] = 1;
	for(int i = 1; i < n - d + 1; i++)
	{
		sum -= a[i - 1];
		sum += a[i + d - 1];
		if(sum % 2 == 0)
			ans[i] = 0;
		else
			ans[i] = 1;
	}
	bool flag = false;
	int co = 0;
	int res = 0;
	for(int i = 1; i < n - d; i++)
	{
		
		if(ans[i] == 1)
		{
			co++;
			flag = true;
			if(co == d)
			{
				res++;
				co = 0;
				flag = false;
			}
		}
		else
		{
			if(flag == true)
			{
				res++;
				flag = false;
			}
			co = 0;
			
		}
	}
	cerr << endl;
	if(co != 0)
		res++;
	cout << res << endl;
}
