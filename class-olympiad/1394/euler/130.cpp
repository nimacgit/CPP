#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int maxn = 1000 * 1000 * 10;
bool notprime[maxn + 10];

void find()
{
	for(int i = 2; i < maxn; i++)
		if(!notprime[i])
			for(int j = 2; j * i < maxn; j++)
				notprime[i * j] = true;
}


int gc(int a, int b)
{
	if(b == 0)
		return a;
	return gc(b, a % b);
}

int A(int n)
{
	
	int k = 1;
	int sum = 1;
	sum = sum % n;
	while(sum != 0)
	{
		k++;
		sum = ((sum * 10 + 1) % n);
	}
	return k;
}

int main()
{
	find();
	int co = 0;
	int sum = 0;
	for(int i = 4; i < maxn && co < 25; i++)
	{
		if(notprime[i] && gc(i, 10) == 1)
		{
			if((i - 1) % A(i) == 0)
			{
				cout << i << endl;
				co++;
				sum += i;
			}
		}
	}
	cout << sum << endl;
}