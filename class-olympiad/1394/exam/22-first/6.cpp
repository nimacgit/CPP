#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int maxn = 10;
int counter = 0;
int a[maxn + 2][maxn + 2];


int main()
{
	for(int i = 1; i <= maxn; i++)
	{
		for(int j = 1; j <= maxn; j++)
			cin >> a[i][j];
	}
	for(int i = 0; i <= maxn; i++)
		a[0][i] = a[i][0] = 40;
	for(int i = 1; i <= maxn; i++)
	{
		for(int j = 1; j <= maxn; j++)
			for(int s1 = -1; s1 < 2; s1++)
				for(int s2 = -1; s2 < 2; s2++)
				{
					if(s1 != 0 || s2 != 0)
						if(a[i][j] > a[i + s1][j + s2])
							counter++;
				}
	}
	cout << counter << endl;

}