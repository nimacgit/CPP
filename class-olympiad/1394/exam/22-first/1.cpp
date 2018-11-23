#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <set>

using namespace std;

const int delta = 46639;

int gc(int a, int b)
{
	if(b == 0)
		return a;
	return gc(b , a % b);
}

int main()
{
	set <int> myset;
	for(int a = 1; a <= 10; a++)
	{
		for(int b = 1; b <= 10; b++)
		{
			for(int c = 1; c <= 10; c++)
			{
				for(int d = 1; d <= 10; d++)
				{
					myset.insert(gc((a | b), c) ^ d);
				}
			}
		}
	}
	cout << myset.size() << endl;
}