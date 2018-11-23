#include <iostream>

using namespace std;

long long a[1000 * 10];

long long C(long long n)
{
	for(long long i = 2; i <= n; i++)
	{
		long long sum = 0;
		for(long long j = 0; j <= i; j++)
			sum += a[i - j]*a[j - 1];
		a[i] = sum;
	}
	return a[n];
}

int main()
{
	a[0] = 1;
	a[1] = 1;
	long long n;
	cin >> n;
	cout << C(n) << endl;
}