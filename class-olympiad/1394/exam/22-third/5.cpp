#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int maxn = 10000;
const int delta = 229939;
const int k = 3;

int main()
{
	int a[8] = {972 , -1, 273, -1, 932, 911, -1, 233};
	int b[8] = {-1, 942, 135, -1, 371, -1, 311, -1};
	int sum = 0;
	for(int x1 = maxn / 10; x1 < maxn; x1++)	
	{
		for(int y1 = maxn / 10; y1 < maxn; y1++)
		{
			int c = 777;
			a[1] = x1;
			b[0] = y1;
			for(int i = 1; i <= k; i++)
				c = (c * a[i-1] + i) % b[i-1];
			if(c == 777)
				sum++;
		}
	}
	cout << sum << endl;

	// 0!!
}