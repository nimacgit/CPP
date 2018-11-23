#include <iostream>

using namespace std;

const int maxn = 10000;
long long d[maxn + 100000];

long long find(long long n)
{
	long long sum = 0;
	for(int i = 1; i * i <= n; i++)
	{
		if(n % i == 0)
		{
			if(n / i != i)
			{
				sum = sum + i + n / i;
			}
			else
				sum += i;
		}
	}
	return sum - n;
}

int main()
{
	long long sum = 0;
	for(long long i = 2; i < maxn; i++)
	{
		if(d[i] == 0)
			d[i] = find(i);
		if(d[i] < maxn)
		{
			if(d[d[i]] == 0) 
				d[d[i]] = find(d[i]);
			if(d[d[i]] == i && d[i] != i)
				sum += i + d[i];
		}
	}
	cout << sum << endl;
}