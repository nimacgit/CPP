#include <iostream>

using namespace std;

int c(int a,int b)
{
	long long sum = 1;
	long long sum1 = 1;
	for(int i = a; i + b > a; i--)
		sum *= i;
	for(int i = b; i > 1; i--)
		sum1 *= i;
	//cout << sum << " " << sum1 << endl;
	return sum / sum1;
}

int main()
{
	long long n,k;
	long long sum; 
	cin >> n >> k;
	if(k > n)
		cout << "0" << endl;
	else
	{
		long long sum = c(n, k);
		for(int i = n; i + k > n; i--)
		{
			sum *= i;
		}
		cout << sum << endl;
	}
}