#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int maxn = 1000 * 1000 * 100;
bool notprime[maxn];

void find()
{
	notprime[1] = true;
	notprime[0] = true;
	for(int i = 2; i < maxn; i++)
		if(!notprime[i])
			for(int j = 2; j * i < maxn ; j++)
				notprime[i * j] = true;
}

int main()
{
	find();
	int sum = 0;
	for (int i = 1; i <= 577; i++) 
	    if (!notprime[(i + 1) * (i + 1) * (i + 1) - i * i * i])
        	sum++;
       cout << sum << endl;
}