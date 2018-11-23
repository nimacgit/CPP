#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int maxn = 15;
const int max2 = 32768;
int d[max2];
vector<int> v[maxn];
int a[maxn][maxn];


int main()
{
	for(int i = 1; i <= max2; i++)
	{
		int s = 0;
		for(int j = 0; j < 31; j++)
		{
			if((i >> j) & 1)
				s++;
		}
		v[s - 1].push_back(i);
	}
	for(int i = 0; i < maxn; i++)
		for(int j = 0; j < maxn; j++)
			cin >> a[i][j];
	for(int i = 0; i < v[0].size(); i++)
		d[v[0][i]] = a[0][maxn - i - 1];
	for(int i = 1; i < maxn; i++)
	{
		for(int j = 0; j < v[i].size(); j++)
		{
			int temp = v[i][j];
			d[temp] = 0;
			for(int k = 0; k < 20; k++)
			{
				if((temp >> k) & 1)
				{
					int dtemp = temp - (1 << k);
					d[temp] = max(d[temp], d[dtemp] + a[i][maxn - k - 1]);
				}
			}
		}
	}
	for(int i = 0 ; i < max2; i++)
		cout <<  d[i] << endl;

}