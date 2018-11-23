#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int maxn = 1000 * 1000 * 1000 ;

bool reverse(long long a)
{
	long long temp = a, rev = 0;
	while(temp)
	{
		rev = rev * 10 + temp % 10;
		temp /= 10;
	}
	a += rev;
	while(a)
	{
		if((a % 10) % 2 == 0)
			return false;
		a /= 10;
	}
	return true;
}

int main()
{
	long long co = 0;
	for(int i = 1; i < maxn; i++)
		if(i % 10 != 0 && reverse(i))
			co++;
	cout << co << endl;
}