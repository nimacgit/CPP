#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int factorial[10] = {1, 1, 2, 6 ,24 , 120, 720, 5040, 40320, 362880};

const int maxn = 1000 * 1000 * 100;

int make(int a)
{
	long long sum = 0;
	while(a)
	{
		sum += factorial[a % 10];
		a /= 10;
	}
	return sum;
}

int main()
{
	long long sum = 0;
	for(int i = 10; i < maxn; i++)
		if(i == make(i))
			sum += i;
	cout << sum << endl;
}