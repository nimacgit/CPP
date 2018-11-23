#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

int k[50];
string s;
int n, ans;

int f(int ne, int i)
{
	while(i < n)
	{
		if(k[i] <= ne)
			return i;
		i++;
	}
}


int main()
{
	cin >> n;
	for(int i = 0, temp; i < n; i++)
	{
		cin >> s;
		k[i] = -1;
		for(int j = 0; j < n; j++)
			if(s[j] == '1')
				k[i] = j;
	}
	for(int i = 0; i < n; i++)
	{
		int l = f(i ,i);
		ans += l - i;
		for(int j = i; j < l; j++)
			swap(k[j], k[l]);
	}
	cout << ans << endl;
}
