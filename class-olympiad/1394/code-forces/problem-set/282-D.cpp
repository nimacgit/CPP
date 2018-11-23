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
bool d[maxn + 10][maxn + 10][maxn + 10];
bool d2[maxn + 10][maxn + 10];
bool sec[2][maxn + 10][maxn + 10];
bool sec2[2][maxn + 10];
int a[3];
int n;

void dyn2()
{
	d2[0][0] = false;
	:sec2[0][0] = true;
	sec[0][0][0] = true;
	for(int i = 1; i <= maxn; i++)
	{
		sec2[1][i] = false;
		d2[0][i] = true;
	}
	sec2[1][1] = true;
	for(int i = 1; i <= maxn; i++)
		for(int j = i; j <= maxn; j++)
		{
			if(i == j)
				d2[i][j] = d[0][i][j] = true;
			else
			{
				if(sec2[i%2][j] || sec2[i%2][j-1])
					d2[i][j] = d[0][i][j] = true;
				else
					d2[i][j] = false;
			}
		}
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	if(n == 1)
	{
		if(a[0] == 0)
			cout << "BitAryo" << endl;
		else
			cout << "BitLGM" << endl;
		return 0;
	}
	dyn2();
	if(n == 2)
	{
		if(d2[a[0]][a[1]])
			cout << "BitLGM" << endl;
		else
			cout << "BitAryo" << endl;
		return 0;
	}
	dyn();
	if(d[a[0]][a[1]][a[2]])
		cout << "BitLGM" << endl;
	else
		cout << "BitAryo" << endl;
	return 0;

}
