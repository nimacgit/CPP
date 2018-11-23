#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;
int n;
const int maxn = 2e6;
bool notp[maxn];

int main()
{
	cin >> n;
	long long ans = 1;
	for(int i = 2; i <= n; i++)
	{
		if(!notp[i])
		{
			if(n % i == 0)
				ans *= i;
			for(int j = 2*i; j <= n; j+=i)
				notp[j] = true;

		}
	}
	cout << ans << endl;
}
