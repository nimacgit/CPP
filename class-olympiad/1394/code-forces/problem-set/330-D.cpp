#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <bits/stdc++.h>
#define x first
#define y second
#define mp make_pair

using namespace std;

typedef pair<int, int> pie;
const int maxn = 1000;
char a[maxn + 10][maxn + 10];
bool seen[maxn + 10][maxn + 10];
vector<pie> myque;
int c, r;
int h[maxn + 10][maxn + 10];

void bfs(pie e)
{
	seen[e.x][e.y] = true;
	myque.push_back(e);
	h[e.x][e.y] = 0;
	for(int i = 0; i < myque.size(); i++)
	{
		pie v = myque[i];
		if(v.x > 0 && !seen[v.x - 1][v.y] && a[v.x-1][v.y] != 'T')
		{
			seen[v.x-1][v.y]=true;
			h[v.x-1][v.y] = h[v.x][v.y] + 1;
			myque.push_back(mp(v.x-1, v.y));
		}
		if(v.y > 0 && !seen[v.x][v.y-1]&& a[v.x][v.y-1] != 'T')
		{
			seen[v.x][v.y-1]=true;
			h[v.x][v.y-1] = h[v.x][v.y] + 1;
			myque.push_back(mp(v.x, v.y-1));
		}
		if(v.x < c - 1 && !seen[v.x+1][v.y]&& a[v.x+1][v.y] != 'T')
		{
			seen[v.x+1][v.y]=true;
			h[v.x+1][v.y] = h[v.x][v.y] + 1;
			myque.push_back(mp(v.x+1, v.y));
		}	
		if(v.y < r - 1 && !seen[v.x][v.y+1]&& a[v.x][v.y+1] != 'T')
		{
			seen[v.x][v.y+1]=true;
			h[v.x][v.y+1] = h[v.x][v.y] + 1;
			myque.push_back(mp(v.x, v.y+1));
		}
	}
}


int main()
{
	cin >> c >> r;
	pie start, pos;
	for(int i = 0; i < c; i++)
	{
		for(int j = 0; j < r; j++)
		{
			h[i][j] = 1000 * 1000 * 100;
			cin >> a[i][j];
			if(a[i][j] == 'E')
				start = mp(i,j);
			else
				if(a[i][j] == 'S')
					pos = mp(i,j);
		}
	}
	bfs(start);
	long long sum = 0;
	for(int i = 0; i < c; i++)
		for(int j = 0; j < r; j++)
		{
			if(a[i][j] != 'T' && a[i][j] != 'E' && a[i][j] != 'S')
				if(h[i][j] <= h[pos.x][pos.y])
				{
					sum+=a[i][j]-'0';
				}
		}
	cout << sum << endl;
}
