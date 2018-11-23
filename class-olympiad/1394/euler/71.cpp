#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int maxn = 1000 * 1000;


int main()
{
	long long num = 3, fnum;
	long long denum = 7, fdenum = maxn;
	long long p = 0, q = 100000000;
	for(;fdenum > 2; fdenum--)
	{
		fnum = (num * fdenum - 1) / denum;
		if(fnum * q > p * fdenum)
		{
			q = fdenum;
			p = fnum;
		}
	}
	cout << p << "  " << q << endl;
}