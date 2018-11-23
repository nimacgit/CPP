#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const long long maxn = 10000000;

int main()
{
	int ten = 1;
	for(long long n = 1; n < maxn; n++)
	{
		int co = 0;
		for(long long r = 1; r <= n; r++)
		{
			if(n * n % r == 0)
				co++;
		}
		if(n == ten)
		{
			ten *= 2;
			cout << n << "  " << co << endl;
		}
		if(co > 1000)
		{
			cout << n << "  " << co << endl;
			return 0;
		}
	}

}