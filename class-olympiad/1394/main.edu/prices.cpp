#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>


using namespace std;

const int maxlist = 16;
const int maxmarket = 100;
int cost[2][maxlist + 10];
int costindex[2][maxlist + 10];
int market[maxmarket + 10][maxlist + 10];
int dist[maxmarket + 10];
int usedis[2][maxmarket + 10];
const int inf = 1000 * 1000 * 100;
int m, n, co, sum;


void dyn()
{
	co = 0;
	sum = dist[0];
	for(int j = 0; j < m; j++)
	{
		usedis[0][0]++;
		sum += market[0][j];
		cost[co][j] = market[0][j];
		costindex[co][j] = 0;
	}
	for(int i = 1; i < n; i++)
	{
		int sum_temp = 0;
		for(int j = 0; j < n; j++)
			usedis[(co + 1) % 2][j] = usedis[co][j];
		for(int j = 0; j < m; j++)
		{
			if(cost[co][j] >= market[i][j])
			{

				cerr << " cost " << i << "  " << j << endl;
				cerr << " bo " << cost[co][j] << "  " << market[i][j] << endl;
				cost[(co + 1) % 2][j] = market[i][j];
				usedis[(co + 1) % 2][costindex[co][j]]--;
				costindex[(co + 1) % 2][j] = i;
				usedis[(co + 1) % 2][i]++;
			}
			else
			{
				cost[(co + 1) % 2][j] = cost[co][j];
				costindex[(co + 1) % 2][j] = costindex[co][j];
			}
		}
		
		for(int l = 0; l < i; l++)
		{
			if(usedis[(co + 1) % 2][l] > 0)
			{
				int newsum1 = dist[l];
				int newsum2;
				if(usedis[(co + 1) % 2][i] > 0)
					newsum2 = 0;
				else
					newsum2 = dist[i];
				for(int j = 0; j < m; j++)
				{
					if(costindex[(co + 1) % 2][j] == l)
					{
						newsum1 += cost[(co + 1) % 2][j];
						newsum2 += market[i][j];
					}
				}
				if(newsum1 >= newsum2)
				{
					for(int j = 0; j < m; j++)
					{
						if(costindex[(co + 1) % 2][j] == l)
						{
							usedis[(co + 1) % 2][l]--;
							usedis[(co + 1) % 2][i]++;
							costindex[(co + 1) % 2][j] = i;
							cost[(co + 1) % 2][j] = market[i][j];
						}
					}
				}
			}
		}
		for(int j = 0; j < m; j++)
			sum_temp += cost[(co + 1) % 2][j];
		for(int j = 0; j < n; j++)
			if(usedis[(co + 1) % 2][j] > 0)
			{
				sum_temp += dist[j];
				cerr << " sum " << i << "  " << j << endl;
			}
		if(sum_temp < sum)
		{
			cerr << sum_temp << "  " << i << endl;
			sum = sum_temp;
			co = (co + 1) % 2;
		}
	}
}

int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		cost[i][0] = cost[i][1] = inf;
		usedis[0][i] = usedis[1][i] = 0;
		scanf("%d", &dist[i]);
		for(int j = 0; j < m; j++)
			scanf("%d", &market[i][j]);
	}
	dyn();
	cout << sum << endl;
	return 0;
}