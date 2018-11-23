/*
ID: michael247
PROG: angry
LANG: C++
*/

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define ff first
#define ss second

using namespace std;

const int maxn = 500 * 1000 + 1000;
typedef pair<int, int> pie;
int n;
vector<int> pos;
int dr[maxn], dl[maxn];


int main()
{
	fstream in("angry.in", ios::in);
	in >> n;
	for(int i = 0; i < n; i++)
	{
		int temp;
		in >> temp;
		pos.push_back(temp);
	}
	sort(pos.begin(), pos.end());
	dl[0] = 0;
	for(int i = 1; i < n; i++)
	{
		for(int j = i - 1; j >= 0; j--)
		{
			if(pos[i] - pos[j] - 1 >= dl[j])
			{
				dl[i] = pos[i] - pos[j];
				j = -1;
			}
			else
			{
				if(pos[i] - pos[j - 1] - 2 >= dl[j])
				{
					dl[i] = dl[j] + 1;
					j = -1;
				}

			}
		}
	}
	dr[n - 1] = 0;
	for(int i = n - 2; i >= 0; i--)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(pos[j] - pos[i] - 1 >= dr[j])
			{
				dr[i] = pos[j] - pos[i];
				j = n + 1;
			}
			else
			{
				if(pos[j + 1] - pos[i] - 2 >= dr[j])
				{
					dr[i] = dr[j] + 1;
					j = n + 1;
				}

			}		
		}
	}
	for(int i = 0; i < n; i++)
		cerr << dl[i] << " ";
	cerr << endl;
	for(int i = 0; i < n; i++)
		cerr << dr[i] << " ";
	cerr << endl;;

	int mini = 1e9 + 7;
	for(int i = 0; i < n; i++)
	{
		if(max(dr[i], dl[i]) < mini)
			mini = max(dr[i], dl[i]);
	}
	cout << mini << endl;



}
