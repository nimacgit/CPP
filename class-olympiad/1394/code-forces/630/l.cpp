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
int dig[10];

int main()
{
	cin >> n;
	int k = 4;
	while(n > 0)
	{
		dig[k] = n % 10;
		n /= 10;
		k--;
	}
	swap(dig[1], dig[2]);
	swap(dig[2], dig[4]);
	for(int i = 0; i < 5; i++)
		n = n * 10 + dig[i];
	cerr << n << endl;
	long long ans = n;
	for(int i = 0; i < 4; i++)
		ans = (ans * n) % 100000;
	n = 0;
	while(ans)
	{
		n = n * 10 + ans % 10;
		ans /= 10;
	}
	for(int i = 0; i < 5; i++, n /= 10)
		cout << n % 10;
	cout << endl;
}
