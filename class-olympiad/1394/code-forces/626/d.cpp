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
const int maxn = 2000 + 100;
const int maxd = 5010;
long long dif[maxd];
int n;
int a[maxn];
long long ans = 0;
long long sumd[maxd];

long long gc(long long n1, long long n2)
{
	if(n2 == 0)
		return n1;
	return gc(n2, n1 % n2);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
			dif[abs(a[i] - a[j])]++;
	long long sum = 0;
	for(int i = 1; i < maxd - 2; i++)
		sumd[i] = sumd[i - 1] + dif[i];
	for(int i = 1; i < maxd - 2; i++)
	{
		for(int j = 1; j < maxd - 2 && i + j <= maxd - 4; j++)
		{
			sum += dif[i] * dif[j] * (sumd[maxd - 3] - sumd[i + j]);	
		}

	}
	long long maxi = sumd[maxd - 3] * sumd[maxd - 3] * sumd[maxd - 3];
	long long md = 1000000;
	long long temp = gc(sum, maxi);
	sum /= temp;
	maxi /= temp;
	ans = sum / maxi;	
	cout << sum / maxi << ".";
	if(ans == 0)
		cout << 0 << endl;
	else
	{
		long long ansi = ((sum - maxi * ans) * md) / maxi;
		while(ansi * 10 < md)
		{
			cout << "0";
			ansi *= 10;
		}
		cout << ansi % md << endl;
	}

}
