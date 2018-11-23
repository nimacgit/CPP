#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int maxn = 10;
int a[3 * maxn][3 * maxn];
int counter = 0;


int main()
{
	for(int i = 9; i < 2 * maxn - 1; i++)
		for(int j = 9; j < 2 * maxn - 1; j++)
			cin >> a[i][j];
	for(int i = 0; i < 9; i++)
		for(int j = 0; j < 3 * maxn; j++)
			a[i][j] = 40;	
	for(int i = 2 * maxn - 1; i < 3 * maxn; i++)
		for(int j = 0; j < 3 * maxn; j++)
			a[i][j] = 40;
	for(int i = 9; i < 2 * maxn - 1; i++)
		for(int j = 0; j < 9; j++)
			a[i][j] = 40;
	for(int i = 9; i < 2 * maxn - 1; i++)
		for(int j = 2 * maxn - 1; j < 3 * maxn; j++)
			a[i][j] = 40;
	for(int n = 2; n < 10; n++)
		for(int i = 9; i < 2 * maxn - 1; i++)
			for(int j = 9; j < 2 * maxn - 1; j++)
				for(int s1 = -1; s1 < 2; s1++)
					for(int s2 = -1; s2 < 2; s2++)
					{
						bool flag = true;
						if(s1 != 0 || s2 != 0)
						{
							for(int l = 1; l < n; l++)
								if(a[i][j] < a[i + l * s1][j + l * s2])
									flag = false;
							if(flag)
								counter++;
						}

					}
	cout << counter << endl;

}