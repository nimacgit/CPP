#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int maxn = 10001;

int gc(int a, int b)
{
	if(b == 0)
		return a;
	return gc(b, a % b);
}

int findper(int a)
{
	int sum = 0;
	int num, denum, rep, repnum, repdenum;
	int maxim = 1, co = 0;
	while(maxim * maxim <= a)
	{
		if(maxim * maxim == a)
			return 0;
		maxim++;
	}
	maxim--;
	num = maxim;
	denum = a - num * num;
	num *= -1;
	while(num <= maxim)
	{
		num += denum;
		co++;
	}
	num -= denum;
	co--;
	rep = co;
	repnum = num;
	repdenum = denum;
	co--;
	while(co != rep || num != repnum || repdenum != denum)
	{
		co = 0;
		denum = (a - num * num) / denum;
		num *= -1;
		while(num <= maxim)
		{
			num += denum;
			co++;
		}
		num -= denum;
		co--;
		sum++;
	}
	return sum;
}

int main()
{
	int co = 0;
	for(int i = 2; i < maxn; i++)
	{
		if(findper(i) % 2 == 1)
		{
			cout << i << endl;
			co++;
		}
	}
	cout << co << endl;
}