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
int mark[10];

unsigned long long f(int a)
{
	long long ans = 1;
	memset(mark, 0 , sizeof mark);
	for(unsigned long long i = 0; i < a; i++)
	{
		ans *= (n - i);
		for(unsigned long long j = a; j > 1; j--)
			if(ans % j == 0 && !mark[j])
			{
				ans /= j;
				mark[j] = true;
			}
	}
	return ans;
}

int main()
{
	cin >> n;
	cout << f(5) + f(6) + f(7) << endl;
}
