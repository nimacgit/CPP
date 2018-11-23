#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int maxrec = 2000000;
const int maxn = 10000;

int abs(int a)
{
	if(a < 0)
		return -1 * a;
	return a;
}

int main()
{
	int minim = 100000000;
	long long num = 0;
	long long temp;
	for(int i = 1; i < maxn; i++)
	{
		for(int j = 1; j < maxn; j++)
		{
			temp = (i * (i - 1) / 2) * (j * (j - 1) / 2);
			if(abs(maxrec - temp) < minim)
			{
				minim = abs(maxrec - temp);
				num = (i - 1) * (j - 1);
			}
		}
	}
	cout << num << endl;
	
}