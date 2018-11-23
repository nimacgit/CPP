#include <iostream>
#include <vector>

using namespace std;

const int maxn = 1000 * 1000 * 100;



int findfac(long long a)
{
	int sum = 0;
	for(int i = 1; i * i <= a; i++)
	{
		if(a % i == 0)
		{
			if((a / i) != i)
				sum += 2;
			else
				sum++;
		}
	}
	return sum;
}

int main()
{
	long long sum = 1;
	for(int i = 2; i < maxn; i++)
	{
		sum += i;
		if(findfac(sum) > 500)
		{
			cout << sum << "  " << i << findfac(sum)<< endl;
			return 0;
		}
	}
}