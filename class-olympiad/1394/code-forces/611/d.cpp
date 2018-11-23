#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define f first
#define s second
using namespace std;

typedef pair<int,int > pie;
const int maxn =  5000;
long long d[maxn + 100][maxn + 100];
bool o[maxn + 100][maxn + 100];
int sum[maxn + 100][maxn + 100];
bool l[maxn + 100][maxn + 100];
int n;
string s;
int mo = 1e9 + 7;



int main()
{
	cin >> n;
	cin >> s;
	for(int i = 0; i < n / 2 + 1; i++)
	{
		for(int j = 0; j <= i; j++)
		{
			l[i][j] = true;
			if(i == j)
			{
				d[i][j] = 1;
				if( i == 0)
					sum[i][j] = 1;
				else
					sum[i][n - j - 1] = (sum[i][n - j - 2] + 1) % mo;
			}
			else if(j + j > i)
			{
				
			}
			else
			{
				d[i][j] = sum[i - j - 1][n - j - 2];
				if(s[i] > s[i - j - 1])
				{
					d[i][j] = (d[i][j] + d[i - j - 1][j]) % mo;
					l[i][j] = false;
					o[i][j] = true;
				}
				else
					if(s[i] == s[i - 1 - j])
					{
						if(o[i - 1][j])

					}
					else 
						l[i][j] = false;
			}
		}
	}




}
