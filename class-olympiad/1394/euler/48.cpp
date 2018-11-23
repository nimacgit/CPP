#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const long long  maxn = 10000000000;

int main()
{
	long long sum = 0;
	long long num = 1;
	for(int i = 1; i <= 1000; i++)
	{
		num = i;
		for(int j = 1; j < i; j++)
		{
			num = (num * i) % maxn;
		}
		cout << num << endl;
		sum = (sum + num) % maxn;
	}
	cout << sum << endl;
}