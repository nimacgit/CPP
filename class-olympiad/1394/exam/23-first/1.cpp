#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int delta = 229939;
int d[delta];

void dynamic()
{
	d[0] = 1;
	for(int i = 1; i < delta + 2; i++)
	{
		if(i % 2 == 1)
			d[i] = (3 * d[i / 2]) % delta;
		else
			d[i] = (2 * d[i / 2]) % delta;
	}
}


int main()
{
	dynamic();
	long long sum = 0, z = 0;
	for(int i = 1; i <= delta + 2; i++)
		z = (z + d[i]) % delta;
	for(int i = 1; i <= delta + 2; i++)
		sum = (sum + i * z) % delta;
	cout << sum << endl;
}