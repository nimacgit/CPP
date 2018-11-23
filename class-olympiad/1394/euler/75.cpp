#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>

using namespace std;

const int maxn = 1500000;
int tri[maxn + 10];
int mlim = sqrt(maxn / 2);
 
long long gc(long long a, long long b)
{
	if(b == 0)
		return a;
	return gc(b, a % b);
}

int main()
{
	int co = 0;
	for (long long m = 2; m < mlim; m++) 
	{
	    for (long long n = 1; n < m; n++) 
	    {
	        if (((n + m) % 2) == 1 && gc(n, m) == 1) 
	        {
	            long long a = m * m + n * n;
	            long long b = m * m - n * n;
	            long long c = 2 * m * n;
	            long long p = a + b + c;
	            while(p <= maxn)
	            {
	                tri[p]++;
	                if (tri[p] == 1) 
	                	co++;
	                if (tri[p] == 2) 
	                	co--;
	                p += a + b + c;
	            }
	        }
	    }
	}
	cout << co << endl;
}