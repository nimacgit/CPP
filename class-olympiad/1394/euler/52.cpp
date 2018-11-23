#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int maxn = 1000 * 1000 * 10;

bool issame(int a, int b)
{
	int c[10], d[10];
	for(int i = 0; i < 10; i++)
		c[i] = d[i] = 0;
	while(a)
	{
		c[a % 10]++;
		a /= 10;
	}
	while(b)
	{
		d[b % 10]++;
		b /= 10;
	}
	for(int i = 0; i < 10; i++)
		if(c[i] != d[i])
			return false;
	return true;
}

int main()
{
	for(int i = 2; i < maxn; i++)
	{
		int flag = true;
		for(int j = 2; j < 7 && flag; j++)
			if(!issame(i, j * i))
				flag = false;
		if(flag)
		{
			cout << i << endl;
			return 0;
		}
	}
}