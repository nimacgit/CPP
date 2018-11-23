#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>

using namespace std;

const int maxn = 1000;
int d[maxn + 10];

int main()
{
	for(int i = 1; i <= maxn; i++)
	{
		double temp;
		for(int j = i; j <= maxn; j++)
		{
			temp = double(sqrt(i * i + j * j));
			if(double(temp) == int(temp))
				if(temp + j + i < maxn)
				{
					cout << i << " " << j << " " << temp << endl;
					d[int(temp + i + j)]++;
				}
		}
	}
	int maxim = 0;
	for(int i = 1; i <= maxn; i++)
	{
		if(d[i] > d[maxim] )
			maxim = i;
	}
	cout << maxim << " " << d[maxim] << endl;
}