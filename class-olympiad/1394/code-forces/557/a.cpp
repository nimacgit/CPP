#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>


using namespace std;

int max1, min1, min2, max2, min3, max3, n, a1, a2, a3;

int main()
{
	cin >> n >> min1 >> max1 >> min2 >> max2 >> min3 >> max3;
	a1 = min1;
	a2 = min2;
	a3 = min3;
	n -= (min1 + min2 + min3);
	if(n > 0)
	{
		if(n > max1 - min1)
		{
			a1 += max1 - min1;
			n -= max1 - min1;
		}
		else
		{
			a1 += n;
			n -= n;
		}
	}
	if(n > 0)
	{
		if(n > max2 - min2)
		{
			a2 += max2 - min2;
			n -= max2 - min2;
		}
		else
		{
			a2 += n;
			n -= n;
		}
	}
	if(n > 0)
	{
		if(n > max3 - min3)
		{
			a3 += max3 - min3;
			n -= max3 - min3;
		}
		else
		{
			a3 += n;
			n -= n;
		}
	}
	cout << a1 << " " << a2 << " " << a3 << endl;
}