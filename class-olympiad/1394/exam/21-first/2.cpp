#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>


using namespace std;

const int delta = 29123;
bool a[delta];

int bmm(int a, int b)
{
	for(int c = a % b; c != 0;)
	{
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}

int main()
{
	long long sum = 1;
	long long i = 2;
	while(!a[sum] || i < 2011)
	{
		a[sum] = true;
		sum = (i * sum / bmm(i, sum)) % delta;
		cout << sum << endl;
		i++;
	}
	cout << sum << endl;
}
