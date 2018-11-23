#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const long long maxn = 10000000000;

int main()
{
	int sum = 0;
	long long a = 28433;
	for(int i = 0; i < 7830457; i++)
		a = (a * 2 ) % maxn;
	a++;
	cout << a << endl;
	while(a)
	{
		sum += a % 10;
		a /= 10;
	}
	cout << sum << endl;
}