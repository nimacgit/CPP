#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

const int maxn = 1000 * 100 + 1000;
int n, k;
int a[maxn];
string s;

int getans()
{
	int one = 0;
	int maxi = 1;
	int s = 0, t = 0;
	one += a[0];
	bool flag;
	while(t < n - 1)
	{
		flag = true;
		while(one < k && t < n - 1)
		{
			t++;
			one += a[t];
		}
		while(one == k && a[t + 1] == 0 && t < n - 1)
			t++;
		maxi = max(maxi, t - s + 1);
		while(one >= k && flag && s <= t && s < n - 1)
		{
			if(s == t)
			{
				t++;
				one += a[s + 1];
				flag = false;
			}
			one -= a[s];
			s++;
		}
	}
	return maxi;

}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	cin >> s;
	for(int i = 0; i < n; i++)
	{
		if(s[i] == 'a')
			a[i] = 0;
		else
			a[i] = 1;
	}
	int maxi = getans();
	for(int i = 0; i < n; i++)
		a[i] = !a[i];
	maxi = max(maxi, getans());
	cout << maxi << endl;
}
