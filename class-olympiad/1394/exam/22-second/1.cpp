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
	for(long long i = 1; i < delta * delta; i *= 2)	
	{
		if(2 * i >= delta * delta)
		{
			cout << (long long)(i * i * 3) << endl;
			return 0;
		}
	}
}