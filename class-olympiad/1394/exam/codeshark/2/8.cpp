#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>

using namespace std;
const int d = 1;
const int delta = 12781;


int ways(int w, int h)
{
	long long sum = 0;
	for(int x1 = 1; x1 <= h + 1; x1++)
	{
		for(int y1 = 1; y1 <= w + 1; y1++)
		{
				for(int x2 = x1; x2 <= h + 1; x2++)
				{
					for(int y2 = 1; y2 <= w + 1; y2++)
					{
						if(x2 > x1 || y2 > y1)
							if(sqrt((y1 - y2) * (y1 - y2) + (x1 - x2) * (x1 - x2)) >= d)
								sum++;
					}
				}
		}
	}
	return sum;
}
int main()
{
	long long sum = 0;
	for(int h = 2; h <= 10; h++)
	{
		for(int w = 2; w <= 10; w++)
		{
			sum = (sum + ways(w,h)) % delta;
		}
	}
	cout << sum << endl;
}