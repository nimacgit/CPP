#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int maxn = 10000;
const int delta = 229939;

int main()
{
	int sum = 0;
	for(int x1 = maxn / 10; x1 < maxn; x1++)	
	{
		for(int y1 = maxn / 10; y1 < maxn; y1++)
		{
			if((((755245 % x1)*y1 + 2) % 942) == 777)
			{
				sum++;
				cout << x1 << " " << y1 << endl;
			}
		}
	}
	cout << sum << endl;
}