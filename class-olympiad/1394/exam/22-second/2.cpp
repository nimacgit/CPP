#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int delta = 11287;

int main()
{
	long long sum = 0;
	for(long long i = 1; i < delta * delta; i *= 2)	
	{
		sum += (i * i * 3);
		if(i >= delta * delta - 3 * i)
		{
			cout << sum << endl;
			return 0;
		}
	}
}