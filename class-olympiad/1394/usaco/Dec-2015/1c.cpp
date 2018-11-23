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

int n, m, d, s;
const int maxn = 200;
bool issick[maxn];
bool isdrink[maxn][maxn];
int tissick[maxn], tisdrink[maxn][maxn];



int main()
{
	ifstream inp;
	ofstream out;
	inp.open("badmilk.in", ios::in);
	inp >> n >> m >> d >> s;
	for(int i = 0; i < d; i++)
	{
		int temp1, temp2, temp3;
		inp >> temp1 >> temp2 >> temp3;
		temp1--;temp2--;
		isdrink[temp1][temp2] = true;
		tisdrink[temp1][temp2] = temp3;
	}
	for(int i = 0; i < s; i++)
	{
		int temp1, temp2;
		inp >> temp1 >> temp2;
		temp1--;
		issick[temp1] = true;
		tissick[temp1] = temp2;
	}
	int maxi = 0;
	for(int i = 0; i < m; i++)
	{
		int co = 0;
		bool flag = true;
		for(int j = 0; j < n; j++)
		{
			if(isdrink[j][i] && issick[j] && tissick[j] > tisdrink[j][i])
				co++;
			else if(issick[j])
					flag = false;
			else if(isdrink[j][i])
				co++;
		}
		if(flag)
			maxi = max(maxi, co);
	}
	out.open("badmilk.out", ios::out);
	out << maxi << endl;
}
