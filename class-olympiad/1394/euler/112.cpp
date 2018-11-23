#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const long long maxn = 1000 * 1000 * 10;

bool isbounce(long long a)
{
	bool de = true, in = true;
	long long dei, ini;
	ini = dei = a % 10;
	a /= 10;
	while(a > 0 && (in || de))
	{
		if(de && a % 10 > dei)
			de = false;
		if(in && a % 10 < ini)
			in = false;
		ini = dei = a % 10;
		a /= 10;
	}
	if(!de && !in)
		return true;
	return false;
}

int main()
{
	long long co = 0;
	for(long long i = 99; i < maxn; i++)
	{
		if(isbounce(i))
			co++;
		if(co * 100 == 99 * i)
			cout << i << endl;
	}
	cout << isbounce(66420) << endl;
}