#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <set>

using namespace std;


const int maxn  = 100;
int n, m;

int main()
{
	cin >> n >> m;
	int co = 0;
	for(int i = 0; i < n; i++)
	{
		
		for(int j = 0; j < m; j++)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			if(x == 1 || y == 1)
				co++;
		}
	}
	cout << co << endl;
}
