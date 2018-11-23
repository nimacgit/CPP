#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

const long long maxn = 100000000000000;


bool isprime(long long a)
{
	for(long long i = 2; i * i <= a; i++)
		if(a % i == 0)
			return false;
	return true;
}

int sumr(int a)
{
	int b = 0;
	while( a > 0)
	{
		b += a % 10;
		a /= 10;
	}
	return b;
}

int main()
{
	for(int i = 1000; i < 10000 ; i++)
	{
		int a = i / 10;
		int b = i / 100;
		if((i % sumr(i) == 0) && (a % sumr(a) == 0) && (b % sumr(b) == 0))
			cout << i << endl;
	}
}