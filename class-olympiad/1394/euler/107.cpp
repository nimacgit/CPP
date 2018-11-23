#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;


const int maxn = 40;
int matr[maxn][maxn];
vector <int> vertix[maxn];
bool check[maxn];


int main()
{
	int ho = 0;
	for(int i = 0; i < maxn; i++)
		for(int j = 0; j < maxn; j++)
		{
			cin >> matr[i][j];
			ho += matr[i][j];
			check[i] = false;
		}
	for(int i = 0; i < maxn; i++)
		for(int j = 0; j < maxn; j++)
			if(matr[i][j] != 0)
				vertix[i].push_back(j);
	vector <int> actives;
	actives.push_back(0);
	long long sum = 0;
	check[0] = true;
	while(actives.size() < 40)
	{
		int minim = 10000000, ver1, ver2;
		for(int i = 0; i < actives.size(); i++)
		{
			for(int j = 0; j < vertix[actives[i]].size(); j++)
			{
				if(!check[vertix[actives[i]][j]])
				{
					if(matr[actives[i]][vertix[actives[i]][j]] < minim)
					{
						minim = matr[actives[i]][vertix[actives[i]][j]];
						ver1 = actives[i];
						ver2 = vertix[actives[i]][j];
					}
				}
			}
		}
		actives.push_back(ver2);
		sum += matr[ver1][ver2];
		check[ver2] = true; 
	}
	ho /= 2;
	cout << ho << endl;
	cout << ho - sum << endl;
	
}