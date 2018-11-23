#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <algorithm>



using namespace std;

const int maxn = 500;

int bears[maxn][maxn];
int q, n, m, maxb, counter;

int findmaxim()
{
	maxb = 0;
	for(int i = 0; i < n; i++)
	{
		counter = 0;
		for(int j = 0; j < m; j++)
		{
			if(bears[i][j])
			{
				counter++;
			}
			else
			{
				if(counter > maxb)
					maxb = counter;
				counter = 0;
			}
		}
		if(counter > maxb)
			maxb = counter;
	}
	return maxb;
}


int main()
{
	cin >> n >> m >> q;
	for(int i = 0; i < n; i++)
		for(int j = 0, temp; j < m; j++)
			cin >> bears[i][j];
	int x, y;
	for(int k = 0; k < q; k++)
	{
		cin >> x >> y;
		x--;
		y--;
		if(bears[x][y])	
			bears[x][y] = 0;
		else
			bears[x][y] = 1;
		cout << findmaxim() << endl;
	}

}