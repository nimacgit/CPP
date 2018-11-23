#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const long long delta = 12569;
const long long maxn = 1000 * 1000 * 100;
const long long num = 963761198400;
long long d[maxn];


long long find(long long a)
{
	if(a < maxn)
		if(d[a] != 0)
			return d[a];
		else
		{
			long long sum = 0;
			for(long long i = 1; i <= a / 2; i++)
				if(a % i == 0)
					sum += find(i);
			return d[a] = sum;
		}
	else
	{
		long long sum = 0;
		for(long long i = 1; i <= a / 2; i++)
			if(a % i == 0)
			{
				if(a == num)
					cout << i << endl;
				sum += find(i);
			}

		return sum;
	}
}

int main()
{
	cout << find(num) << endl;
}