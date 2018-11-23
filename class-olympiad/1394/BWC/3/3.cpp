#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;
const int maxn = 3000;
long long e[2][maxn];
long long t[2][maxn];
long long n, m, f;
long long maxi = 1000000000;
long long ans = 0;

int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		e[0][i] = t[0][i] = 1;
	cin >> f;
	f--;
	e[0][f] = 0;
	for(int i = 1; i < m; i++)
	{
		cin >> f;
		f--;
		for(int j = 1; j < n - 1; j++)
		{
			e[i % 2][j] = e[(i + 1) % 2][j - 1] + e[(i+1)%2][j + 1];
			t[i % 2][j] = t[(i + 1) % 2][j - 1] + t[(i+1)%2][j + 1];
		}
		t[i%2][0] = t[(i + 1) % 2][1];
		t[i%2][n - 1] = t[(i + 1)%2][n - 2];
		e[i%2][0] = e[(i + 1) % 2][1];
		e[i%2][n - 1] = e[(i + 1)%2][n - 2];
		e[i%2][f] = 0;
	}
	long long maxim = 0;
	for(int i = 0; i < n; i++)
	{
		ans += e[(m+1)%2][i];
		maxim += t[(m+1)%2][i];
	}
	ans = (ans * (long long)1000000000) /  maxim;
	if(ans == 0)
		cout << "0.000000000" << endl;
	else
	{
		cout << "0.";
		long long temp = 1;
		while(temp * ans < maxi / 10)
		{
			cout << 0;
			temp *= 10;
		}
		cout << ans << endl;
	}


}
