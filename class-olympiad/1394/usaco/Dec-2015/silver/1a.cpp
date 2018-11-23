#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair

using namespace std;

typedef pair<int, int> pie;
const int maxn = 110;
int n, m;
vector<pie> room[maxn][maxn];
bool light[maxn][maxn];
bool cango[maxn][maxn];

int main()
{
	ifstream inp("lightson.in", ios::in);
	inp >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int temp1, temp2, temp3, temp4;
		inp >> temp1 >> temp2 >> temp3 >> temp4;
		room[temp1][temp2].push_back(mp(temp3, temp4));
	}
	cango[1][1] = true;
	light[1][1] = true;
	for(int i = 0; i < n * n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			for(int l = 1; l <= n; l++)
			{
				if(light[j][l] && (cango[j-1][l] || cango[j+1][l] || cango[j][l - 1] || cango[j][l+1] || cango[j][l]))
				{
					while(!room[j][l].empty())
					{
						int temp1 = room[j][l].back().first, temp2 = room[j][l].back().second;
						room[j][l].pop_back();
						light[temp1][temp2] = true;
					}
					cango[j][l] = true;
				}
					
			}
		}
	}
	int co = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(light[i][j])
			{
				co++;
			}
	ofstream out("lightson.out", ios::out);
	out << co << endl;
	return 0;


}
