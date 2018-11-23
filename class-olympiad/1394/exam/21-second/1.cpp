#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>


using namespace std;

const int maxn = 9;
const int delta = 28813;
int h[maxn + 4][maxn + 4];
int x, y;

int main()
{
	x = y = 1;
	for(int i = 0; i < delta - 1; i++)
	{
		if(h[x][y] % 4 == 0)
		{
			x = ((x - 1) + 9) % 9;
			h[x][y]++;
		}
		else
		{
			if(h[x][y] % 4 == 1)
			{
				y = (y + 1) % 9;
				h[x][y]++;
			}
			else
			{
				if(h[x][y] % 4 == 2)
				{
					x = (x + 1) % 9;
					h[x][y]++;
				}
				else
				{
					y = ((y - 1) + 9) % 9;
					h[x][y]++;
				}
			}
		}
	}
	long long sum = 1;
	for(int i = 0; i < maxn; i++)
	{
		for(int j = 0; j < maxn; j++)
		{
			sum = sum * h[i][j] % delta;
		}
	}
	cout << sum << endl;
}