#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <set>
#include <list>

using namespace std;

const int maxp = 24;
const int maxn = 256;
set <int> myset;


int main()
{
	for(int i = 1; i < (1 << (maxp + 1) / 2); i++)	
	{
		int sum = i;
		for(int k = 2; k * i + sum < maxn; k++)
		{
			myset.insert(sum);
			sum += k * i;
			k *= 2;
		}
	}
	cout << myset.size() << endl;
}