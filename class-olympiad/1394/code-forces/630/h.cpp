#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;


long long n;
bool mark[10];

long long f(int a)
{
	long long ans = 1;
	memset(mark, 0, sizeof mark);
	for(int i = 0; i < a; i++)
	{
		ans *= (n - i);
		for(int j = 2; j <= a; j++)
			if(ans % j == 0 && !mark[j])
			{
				mark[j] = true;
				ans /= j;
			}
	}
	return ans;
}


int main()
{
	cin >> n;
	cout << f(5) * n * (n-1) * (n-2) * (n-3) * (n-4) << endl;
}
