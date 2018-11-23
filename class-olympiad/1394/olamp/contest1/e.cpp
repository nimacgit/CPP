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

const int maxn = 300;
int d[maxn + 100][maxn + 100];
int a[maxn + 100][maxn + 100];
int n;
int sum = 0;


void dyn()
{
	d[0][0] = a[0][0];
	for(int i = 1; i < n; i++)
	{
		d[0][i] = a[0][i] + d[0][i -1];
		d[i][0] = a[i][0] + d[i - 1][0];
	}
	for(int i = 1; i < n; i++)
		for(int j = 1; j < n; j++)
			d[i][j] = a[i][j] + max(d[i - 1][j], d[i][j - 1]);
}

void go()
{
	int x = n - 1, y = n - 1;
	sum += a[x][y];
	a[x][y] = 0;
	for(int i = 0; i < 2 * n - 2; i++)
	{
		if(x == 0)
			y--;
		else if(y == 0)
			x--;
		else
		{
			if(d[x - 1][y] > d[x][y - 1])
				x--;
			else
				y--;
		}
		cerr << " x,y " << x << " " << y << " " << a[x][y] << endl;
		sum += a[x][y];
		a[x][y] = 0;
	}
	cerr << "fin" << endl;
}

void cou()
{
	for(int i = 0; i < n; i++)
	{
		cerr << i << " : ";
		for(int j = 0; j < n; j++)
			cerr << d[i][j] << " ";
		cerr << endl;
	}
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
	dyn();
	cou();
	go();
	cerr << sum << " " << d[n-1][n-1] << endl;
	dyn();
	cou();
	go();
	cerr << " " << d[n-1][n-1] << endl;
	cout << sum << endl;
}
