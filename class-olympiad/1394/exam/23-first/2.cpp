#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const long long delta = 229939;



/*
int main()
{
	long long sum = 0, z = 0;
	for(long long i = 1; i < delta * delta + 3; i++)
	{
		long long temp = 1;
		long long three = __builtin_popcountll(i);
		long long two = __builtin_ctzll(i);
		while(three)
		{
			temp = (temp * 3) % delta;
			three--;
		}
		while(two)
		{
			temp = (temp * 2) % delta;
			two--;
		}
		z = (z + temp) % delta;
		//cout << i << "  " << temp << endl;
	}
	for(long long i = 1; i < delta * delta + 3; i++)
		sum = (sum + z * i) % delta;
	cout << sum << endl;
}
*/

long long d[delta];

void dynamic()
{
	d[0] = 1;
	for(int i = 1; i < delta + 3; i++)
	{
		if(i % 2 == 1)
			d[i] = (3 * d[i / 2]); //% delta;
		else
			d[i] = (2 * d[i / 2]); // % delta;
	}
}

long long g(long long a)
{
	long long sum = 0, z = 0;
	for(int i = 1; i < a; i++)
	{
		z = (z + d[i]); //% delta;
	}
	for(int i = 1; i < a; i++)
		sum = (sum + i * z); // % delta;
	return sum;
}


int main()
{
	long long two = 2;
	dynamic();
	for(int i = 2; i < delta + 3; i++)
	{
		if(i == two)
		{
			cout << g(i) << endl;
			two *= 2;

		}
	}
}