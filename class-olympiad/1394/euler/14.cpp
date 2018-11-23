#include <iostream>

using namespace std;

const long long maxn = 1000 * 1000;

long long d[4 * maxn];

long long findchane(long long n)
{
	long long i = 1;
	bool flag = false;
	for(; n != 1; i++)
	{
		if(n % 2 == 0)
		{
			n = n / 2;
		}
		else
			n = 3 * n + 1;
		//if(d[n] != 0)
			//return i + d[n] + 1;
	}
	return i;
}

int main()
{
	d[1] = 1;
	long long maximum = 1;
	for(long long i = 1; i < maxn; i++)
	{
		//cout << i << "  " << d[i - 1] << endl;
		if(d[i] == 0)
		{
			d[i] = findchane(i);
		}
		for(long long j = 2; i * j < 4 * maxn; j *= 2)
			d[i * j] = d[i * j / 2] + 1;
		if(d[i] > d[maximum])
			maximum = i;
	}
	cout << maximum << endl;
}