#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int maxn = 10;
int a[maxn][maxn];
int d[maxn][maxn][8];
int maxi = 0, maxj = 0, maxk = 0;

pair <int, int> finddirection(int k)
{
	int x,y;
	switch(k % 4)
	{
		case 0:
			x = 0;
			y = -1;
		break;
		case 1:
			x = 1;
			y = -1;
		break;
		case 2:

			x = -1;
			y = 0;
		break;
		case 3:
			x = -1;
			y = -1;
		break;
	}
	return make_pair(x, y);
}



void dynamic()
{
	d[0][0][0] = d[0][0][1] = d[0][0][2] = d[0][0][3] = 1;
	d[0][0][4] = d[0][0][5] = d[0][0][6] = d[0][0][7] = 1;
	for(int i = 1 ; i < maxn; i++)
	{
		d[0][i][0] = d[0][i][1] = d[0][i][2] = d[0][i][3] = 1;
		d[0][i][4] = d[0][i][5] = d[0][i][6] = d[0][i][7] = 1;
		int x, y, k = 2;
		pair <int ,int> temp;
		temp = finddirection(k);
		x = temp.first;
		y = temp.second;
		if(a[0][i] > a[0][i + x])
			d[0][i][k] = d[0][i + x][k] + 1;
		else if(a[0][1] < a[0][i + x])
			d[0][i][k + 4] = d[0][i + x][k + 4] + 1;
		else
		{
			d[0][i][k] = d[0][i + x][k] + 1;
			d[0][i][k + 4] = d[0][i + x][k + 4] + 1;
		}


	}
	for(int i = 1; i < maxn; i++)
	{
		d[i][0][0] = d[i][0][1] = d[i][0][2] = d[i][0][3] = 1;
		d[i][0][4] = d[i][0][5] = d[i][0][6] = d[i][0][7] = 1;
		for(int j = 0; j < maxn; j++)
		{
			for(int k = 0; k < 4; k++)
			{
				pair <int, int> temp;
				temp = finddirection(k);
				int x, y;
				x = temp.first;
				y = temp.second;
				d[i][j][k] = d[i][j][k + 4] = 1;
				if(a[i][j] > a[i + y][j + x])
					d[i][j][k] = d[i + y][j + x][k] + 1;
				else if(a[i][j] < a[i + y][j + x])
					d[i][j][k + 4] = d[i + y][j + x][k + 4] + 1;
				else
				{
					d[i][j][k] = d[i + y][j + x][k] + 1;
					d[i][j][k + 4] = d[i + y][j + x][k + 4] + 1;
				}
				if(j == 0)
					break;
			}
		}
	}
}


int findmaxim()
{
	for(int i = 1; i < maxn; i++)
		for(int j = 1; j < maxn; j++)
			for(int k = 0; k < 8; k++)
				if(d[i][j][k] > d[maxi][maxj][maxk])
				{
					//cout << maxi << "  " << maxj << "  " << maxk << endl;
					maxi = i;
					maxj = j;
					maxk = k;
				}
	return d[maxi][maxj][maxk];
}

int answer(int maximd)
{
	int x, y, sum = 1, maximumd = 0;
	for(int i = 0; i < maxn; i++)
		for(int j = 0; j < maxn; j++)
			for(int k = 0; k < 8; k++)
			{
				//cerr << " d " << d[i][j][k] << endl;
				if(d[i][j][k] == maximd)
				{
					int x, y;
					pair<int , int> temp;
					temp = finddirection(k % 4);
					x = temp.first;
					y = temp.second;
					sum = 1;
					for(int l = 0; l < maximd; l++)
						sum *= a[i + l * y][j + l * x];
					if(maximumd < sum)
						maximumd = sum;
				}
			}
	return maximumd;
}


int main()
{
	for(int i = 0; i < maxn; i++)	
	{
		for(int j = 0; j < maxn; j++)
			cin >> a[i][j];
	}
	int maxd;
	dynamic();
	maxd = findmaxim();
	cerr << maxi << "  " << maxj << " " << maxk << endl;
	cerr << maxd << endl;
	cout << answer(maxd) << endl;


	//cout << maxi << "  " << maxj << "  " << maxk << endl;
	/*for(int i = 0; i < maxn; i++)	
	{
		for(int j = 0; j < maxn; j++)
			cout << d[i][j] << " " << parent[i][j] << "   ";
		cout << endl;
	}

	*/
	// maxi = 9 j = 9 k = 1
}
