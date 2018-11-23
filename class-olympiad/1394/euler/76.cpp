#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <set>
#include <list>

using namespace std;

const int maxn = 100;
long long sum = 0;
int a[maxn + 2];
int ways = 0;

int main()
{
	int i = 1;
	while(a[100] != 1)
	{
		if(sum >= 100)
		{
			if(sum == 100)
				ways++;
			i = 1;
			while(sum > 100)
			{
				sum -= (a[i] * i);
				a[i] = 0;
				i++;
			}
			a[i]++;
			sum += i;
		}
		else
		{
			a[1]++;
			sum++;
		}
	}
	cout << ways << endl;
//	for(long long i = 0; i < maxn; i++)
//		cout << d[i] << endl;
}