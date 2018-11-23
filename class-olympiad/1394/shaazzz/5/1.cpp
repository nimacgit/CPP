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
const int maxn = 2000;
bool t[2][maxn][maxn];
string s;
int n, m;


long long getans(int pos)
{
	cerr << "check" << endl;
	long long ans = 0;
	int d[maxn][maxn];
	int sum[maxn];
	cerr << "YES" << endl;
	memset(sum, 0, sizeof sum);
	for(int i = 0; i < n; i++)
	{
		int have = 0, pas = 0;
		d[i][0] = 0;
		for(int j = 0; j < m; j++)
		{
			if(t[pos][i][j])
			{
				ans += (i * (i + 1)) / 2 + sum[0];
				d[i][0] += j;
				have++;
			}
		}
		cerr << i << endl;
		sum[0] += d[i][0];
		for(int j = 1; j < m; j++)
		{
			d[i][j] = d[i][j - 1] + 2*pas - have;
			sum[j] += d[i][j];
			if(t[pos][i][j])
			{
				ans += (i * (i + 1))/2 + sum[j];
				pas++;
			}
		}
		
	}
	return ans;
}

int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		cin >> s;
		for(int j = 0; j < m; j++)
		{
			if(s[j] == 'M')
				t[0][i][j] = true;
			else if(s[j] == 'S')
				t[1][i][j] = true;
		}
	}
	cerr << "what" << endl;
	long long an =  getans(0);
	cerr << "no" << endl;
	an +=	getans(1);
	cout << an << endl;
}
