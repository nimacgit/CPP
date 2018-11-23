#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <set>

using namespace std;

const int delta = 46639;
const int maxn = 1000;

int gc(int a, int b)
{
	if(b == 0)
		return a;
	return gc(b , a % b);
}

int main()
{
	set <int> myset;
	int maxim = 0;
	for(int a = 1; a <= maxn; a++)
	{
		for(int b = 1; b <= maxn; b++)
		{
			for(int c = 1; c <= maxn; c++)
			{
				for(int d = 1; d <=	maxn; d++)
				{
					int temp = (gc((a | b), c) ^ d);
					myset.insert(temp);
					if(temp > maxim)
					{
						cout << temp << " a = " << a << "  " << b << "  " << c << "  " << d << endl;
						maxim = temp;
					}
				}
			}
		}
	}
	//ans = 1023, 0;
}