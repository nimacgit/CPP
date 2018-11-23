#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int maxn = 1000 * 1000;

int gc(int a, int b)
{
	if(b == 0)
		return a;
	return gc(b, a % b);
}

int A(int n)
{
	if(gc(n, 10) != 1) 
		return 0;
	int k = 1;
	int sum = 1;
	sum = sum % n;
	while(sum != 0)
	{
		k++;
		sum = ((sum * 10 + 1) % n);
	}
	return k;
}

int main()
{
	int n = 1;
	while(A(n) < maxn)
	{
		n += 2;
	}
	cout << n << endl;
}