#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int maxn = 20;

int main()
{
	int x = 0, y = 0;
	int counter = 0;
	for(int i = 1; i <= maxn; i++)
	{
		int temp = i;
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
	}
	cout << x << " " << y << endl;
}