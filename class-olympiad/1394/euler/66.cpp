#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>

using namespace std;

const unsigned long long maxn = 1000;



int main()
{
	unsigned long long maxim = 0;
	unsigned long long index = 0;
	for(unsigned long long x = 1000 * 1000 * 1000; x > 10; x--)
	{
		cout << x << endl;
		for(unsigned long long d = 2; d < x; d++)
		{
			if( (x * x - 1) % d == 0)
			{
				double temp = sqrt((x * x - 1) / d);
				if((double)temp == (int)temp)
				{
					cout << x << endl;
						return 0;
				}
			}
		}
	}
}