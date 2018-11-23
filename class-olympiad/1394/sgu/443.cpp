#include <iostream>

using namespace std;

int main()
{
	int a, b, lpa, lpb;
	cin >> a >> b;
	long long sum1 = 0, sum2 = 0;
	for(int i = 2; i <= a; i++)
	{
		if(a % i == 0)
		{
			lpa = i;
			sum1 += i;
			while(a % i == 0)
				a /= i;
		}

	}
	sum1 -= lpa;
	sum1 = lpa - sum1;
	for(int i = 2; i <= b; i++)
	{
		if(b % i == 0)
		{
			lpb = i;
			sum2 += i;
			while(b % i == 0)
				b /= i;
		}

	}
	//cout << sum2 << endl;
	sum2 -= lpb;
	sum2 = lpb - sum2;
	//cout << sum1 << " " << sum2 << endl;
	if(sum1 > sum2)
		cout << "a" << endl;
	else
		cout << "b" << endl;
	
}