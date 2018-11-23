#include <iostream>

using namespace std;

bool isprime(long long a)
{
	if(a == 1 )
		return false;
	for(long long i = 2; i * i <= a; i++)
		if(a % i == 0)
			return false;
	return true;
}

int main()
{
	double perc = 100;
	int sum = 0;
	int roun = 1;
	for(int i = 3; perc >= 10; i += 2 )
	{
		if(isprime(i * i - i + 1))
			sum++;
		if(isprime(i * i - 2 * (i - 1)))
			sum++;
		if(isprime(i * i - 3 * (i - 1)))
			sum++;
		roun += 4;
		perc = (100.0 * sum) / (double)roun;
		if(perc < 10)
			cout << i << endl;
	}

}