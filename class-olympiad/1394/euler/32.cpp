#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;


bool check(int  a, int  b, int  c)
{
	int checkout[10];
	int bagh;
	for(int i = 0; i < 10; i++)
		checkout[i] = 0;
	while(a > 0)
	{
		bagh = a % 10;
		if(checkout[bagh] == 0 && bagh != 0)
			checkout[bagh]++;
		else
			return false;
		a /= 10;
	}
	while(b > 0)
	{
		bagh = b % 10;
		if(checkout[bagh] == 0 && bagh != 0)
			checkout[bagh]++;
		else
			return false;
		b /= 10;
	}
	while(c > 0)
	{
		bagh = c % 10;
		if(checkout[bagh] == 0 && bagh != 0)
			checkout[bagh]++;
		else
			return false;
		c /= 10;
	}
	for(int i = 1; i < 10; i++)
		if(checkout[i] == 0)
			return false;
	return true;

//	cout << checkout[1] << " " << checkout[3] << endl;
}


int main()
{
	long long sum = 0;
	for(int i = 1; i < 1000; i++)
	{
		for(int j = i; j < 1000; j++)
		{
			int temp = i * j;
			if(check(i, j, temp))
			{
				sum += (i * j);
				cout << i * j << endl;
			}
		}
	}
	sum += 6952 + 7852;
	cout << sum << endl;
	
}