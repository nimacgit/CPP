#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;


const int maxn = 200;
bool a[maxn][maxn];
int n, d, co = 0, maxi = 0;
string s;

int main()
{
	cin >> n >> d;
	for(int i = 0; i < d; i++)
	{
		bool flag = false;
		cin >> s;
		for(int j = 0; j < n; j++)
			if(s[j] == '0')
				flag = true;
		if(flag)
			co++;
		else
		{
			maxi = max(maxi, co);
			co = 0;
		}
	}
	maxi = max(maxi, co);
	cout << maxi << endl;
}
