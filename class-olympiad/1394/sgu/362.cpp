#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <list>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>



using namespace std;

const int maxn = 10;
bool a[maxn + 10][maxn + 10];
int i, j, m, n;
bool doesgo = true;

int main()
{
	cin >> n >> m >> i >> j;
	a[i][j] = true;
	while(doesgo)
	{
		doesgo = false;
		if(i < n && !a[i + 1][j])
		{
			a[i + 1][j] = true;
			i++;
			cout << "D";
			doesgo = true;
		}
		else if(j > 1 && !a[i][j - 1])
		{
			j--;
			a[i][j] = true;
			cout << "L";
			doesgo = true;
		}
		else if(i > 1 && !a[i - 1][j])
		{
			i--;
			a[i][j] = true;
			cout << "U";
			doesgo = true;
		}
		else if(j < m && !a[i][j + 1])
		{
			j++;
			a[i][j] = true;
			cout << "R";
			doesgo = true;
		}
	}
	cout << endl;
}