#include <iostream>

using namespace std;

long long a[1000 * 10];

long long C(long long n)
{
	long long sum = 0;
	for(long long i = 1; i <= n; i++)
	{
		if(a[n - i] == 0)
			C(n - i);
		if(a[i] == 0)
			C(i - 1);
		sum += a[i - 1]*a[n - i];
	}
	return a[n] = sum;
}

int main()
{
	time_t t1,t2;
	a[0] = 1;
	a[1] = 1;
	long long n;
	cin >> n;
	cout << C(n) << endl;
}