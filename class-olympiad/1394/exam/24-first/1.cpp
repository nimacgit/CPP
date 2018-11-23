#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int delta = 229939;
int maxn = 10;
long long two[50];


long long findmin()
{
	long long sum = 0;
	for(int i = 0; i <= maxn; i++)
	{
		for(int j = 0; j < maxn; j++)
		{
			if(j < i)
				sum += (two[maxn - i] * two[j]);
			else
				sum += (two[maxn - 1 - i] * two[j]);
		}
	}
	return sum;
	
}


int main()
{
	two[0] = 1;
	for(int i = 1; i <= maxn; i++)
		two[i] = (long long)2 * two[i - 1];
	for(int i = 1; i < 40; i++)
	{
		maxn = i;
		cout << i << " " << findmin() << endl;
	}
}
