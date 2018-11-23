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
long long n, a1, a2, b1 ,b2, r1, r2;
long double dis[3][maxn];
int dif[2][2];

long long pow2(long long a)
{
	return a * a;
}


int main()
{
	cout.precision(13);
	cout << fixed;
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> a1 >> a2 >> b1 >> b2 >> r1 >> r2;
	cin >> n;
	long long x, y;
	for(int i = 0 ; i < n; i++)
	{
		cin >> x >> y;
		dis[0][i] = sqrt(pow2(x - a1) + pow2(y - a2));
		dis[1][i] = sqrt(pow2(x - b1) + pow2(y - b2));
		dis[2][i] = sqrt(pow2(x - r1) + pow2(y - r2));
	}
	if(n == 1)
	{
		cout << min(dis[0][0] , dis[1][0]) + dis[2][0] << endl;
		return 0;
	}
	if(dis[2][0] - dis[0][0] > dis[2][1] - dis[0][1])
	{
		dif[0][0] = 0;
		dif[0][1] = 1;
	}
	else
	{
		dif[0][0] = 1;
		dif[0][1] = 0;
	}
	if(dis[2][0] - dis[1][0] > dis[2][1] - dis[1][1])
	{
		dif[1][0] = 0;
		dif[1][1] = 1;
	}
	else
	{
		dif[1][0] = 1;
		dif[1][1] = 0;
	}
	cerr << dif[0][0] << " " << dif[0][1] << " " << dif[1][0] << " " << dif[1][1] << endl;
	for(int i = 2; i < n; i++)
	{
		if(dis[2][i] - dis[0][i] > dis[2][dif[0][0]] - dis[0][dif[0][0]])
		{
			swap(dif[0][0], dif[0][1]);
			dif[0][0] = i;
		}
		else if(dis[2][i] - dis[0][i] > dis[2][dif[0][1]] - dis[0][dif[0][1]])
		{
			dif[0][1] = i;
		}
		if(dis[2][i] - dis[1][i] > dis[2][dif[1][0]] - dis[1][dif[1][0]])
		{
			swap(dif[1][0], dif[1][1]);
			dif[1][0] = i;
		}
		else if(dis[2][i] - dis[1][i] > dis[2][dif[1][1]] - dis[1][dif[1][1]])
		{
			dif[1][1] = i;
		}
	}
	long double sum = 0;
	for(int i = 0; i < n; i++)
		sum += dis[2][i] + dis[2][i];
	if(dif[0][0] == dif[1][0])
	{
		int f1 = dif[0][0], f2 = dif[0][1], s1 = dif[1][0], s2 = dif[1][1];
		if(dis[2][f1] - dis[0][f1] + dis[2][s2] - dis[1][s2] > dis[2][f2] - dis[0][f2] + dis[2][s1] - dis[1][s1])
		{
			cout << sum - (dis[2][f1] - dis[0][f1] + dis[2][s2] - dis[1][s2]) << endl;
		}
		else
			cout << sum - (dis[2][f2] - dis[0][f2] + dis[2][s1] - dis[1][s1]) << endl;
	}
	else
	{
		int f = dif[0][0], s = dif[1][0];
		cout << sum - (dis[2][f] - dis[0][f]) - (dis[2][s] - dis[1][s]) << endl;
	}
}
