#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <list>
#include <math.h>


using namespace std;


const long long maxsq = 30000;
bool issquare[maxsq * maxsq];

void find()
{
	for(long long i = 1; i < maxsq; i++)
		issquare[i * i] = true;
}

long long ab(long long a)
{
	if(a < 0)
		return -1 * a;
	return a;
}

bool checksquare(long long a)
{
	if(a < maxsq * maxsq)
		return issquare[a];
	return ((double)sqrt(a) == (int)sqrt(a));
}

int main()
{
	find();
	long long a, b, c;
	for(int i = 1; i < maxsq; i++)
	{
		a = i * i;
		for(int j = i - 1; j > 0; j--)
		{
			b = j * j;
			for(int k = j - 1; k > 0; k--)
			{
				c = k * k;
				if((a + b - c) % 2 == 0 && (a + c - b) % 2 == 0 && (b + c - a) % 2 == 0)
				{
					if(checksquare(b - c) && checksquare(a - c) && checksquare(a - b))
					{
						cout << (a + b + c) / 2 << endl;
						return 0;
					}
				}
			}
		}
	}
}