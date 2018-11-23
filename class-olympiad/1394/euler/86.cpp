#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>

using namespace std;

const int maxn = 1000 * 10;

int main()
{
	int co = 0;
	for(long long m = 1; m <= maxn; m++)
	{
		for(long long n = 1; n <= m; n++)
		{
			for(long long l = 1; l <= n; l++)
			{
				double temp = sqrt((l + n) * (l + n) + m * m);
				if((double)temp == (int)temp)
				{
					co++;
				}
				if(co > 1000 * 1000)
				{
					cout << m << endl;
					return 0;
				}
			}
		}
	}
	cout << co << endl;
}