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
bool seen[maxn][maxn];
bool cango[maxn][maxn];
bool isligth[maxn][maxn];
int co = 0;

void bfs(int x, int y)
{
	if(x < 1 || y < 1 || y > n || x > n)
		return;
	if(cango[x][y + 1] || cango[x][y-1] || cango[x+1][y] || cango[x-1][y]);
	{
		cango[x][y] = true;
		seen[x][y] = true;
		while(!room[x][y].empty())
		{
			int temp1 = room[x][y].back().first, temp2 = room[x][y].back().second;
			isligth[temp1][temp2] = true;
			if(!seen[temp1][temp2])
				bfs(temp1, temp2);
			room[x][y].pop_back();
		}
		if(!seen[x - 1][y] && isligth[x-1][y])
		{
			cango[x-1][y] = true;
			bfs(x-1, y);
		}
		if(!seen[x + 1][y] && isligth[x+1][y])
		{
			cango[x+1][y] = true;
			bfs(x+1,y);
		}
		if(!seen[x][y - 1] && isligth[x][y-1])
		{
			cango[x][y-1] = true;
			bfs(x, y-1);
		}
		if(!seen[x][y + 1] && isligth[x][y+1])
		{
			cango[x][y+1] = true;
			bfs(x, y+1);
		}
	}
}


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
	isligth[1][1] = true;
	cango[1][1] = true;
	bfs(1,1);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(isligth[i][j])
			{
				co++;
			}
	ofstream out("lightson.out", ios::out);
	out << co << endl;
	return 0;


}
