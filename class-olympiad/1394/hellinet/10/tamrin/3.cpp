#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int maxn = 100;
int a[maxn + 10][maxn + 10];
bool d[maxn + 10][maxn + 10];
int x = 0, y = 0, way = 0, n;
int co = 0;

void move()
{
	switch(way)
	{
		case 0:
			if(y + 1 < n && d[x][y + 1])
			{
				y++;
				d[x][y] = false;
			}
			else
			{
				way++;
				co++;
				way %= 4;
				move();
			}
			break;
		case 1:
			if(x + 1 < n && d[x + 1][y])
			{
				x++;
				d[x][y] = false;
			}
			else
			{
				way++;
				co++;
				way %= 4;
				move();
			}
			break;
		case 2:
			if(y - 1 >= 0 && d[x][y - 1])
			{
				y--;
				d[x][y] = false;
			}
			else
			{
				way++;
				co++;
				way %= 4;
				move();
			}
			break;
		case 3:
			if(x - 1 >= 0 && d[x - 1][y])
			{
				x--;
				d[x][y] = false;
			}
			else
			{
				way++;
				co++;
				way %= 4;
				move();
			}
			break;
	}
}


int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			d[i][j] = true;
	d[0][0] = false;
	for(int i = 1; i < n * n; i++)
	{
		move();
	}
	cout << co << endl;
}