#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <set>
#include <math.h>

using namespace std;

const unsigned long long maxn = 1000;


int main()
{
	unsigned long long bo = 0;
	for(unsigned long long i = 0; i < maxn; i++)
	{
		for(unsigned long long j = 0 ; j < 10; j++)
		{
			if(i - 1 <= i * log10(j) && i > i * log10(j))
			{
				cout << i << "  " << j << endl;
				bo++;
			}
		}
	}
	cout << bo << endl;
}