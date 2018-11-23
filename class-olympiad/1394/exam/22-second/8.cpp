#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const long long delta = 11287;
const long long maxn = delta * delta;

int main()
{
	long long x = 0, y = 0;
	long long counter = 0;
	for(long long i = 1; i <= maxn; i++)
	{
		long long temp = i;
		while(temp % 2 == 0)
		{
			counter++;
			temp /= 2;
		}
		counter = counter % 4;
		if(counter == 1)
		{
			x += temp;
		}
		else
		{
			if(counter == 2)
			{
				y -= temp;
			}
			else
			{
				if(counter == 3)
				{
					x -= temp;
				}
				else
				{
					y += temp;
				}
			}
		}
		if(y == -666016)
			cout << x << "  i= " << i << endl;
		//cout << x << "  " << y << endl;
	}
	cout << x << " " << y << endl;
}