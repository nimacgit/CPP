#include <iostream>
#include <vector>
using namespace std;

int m,n,k,a;
vector<int> primes;
vector<int> numprimes;


int main()
{
	primes.clear();
	numprimes.clear();
	cin >> n >> m >> k;
	for(int i = 2; i <= k; i++)
	{
		if(k % i == 0)
		{
			primes.push_back(i);
			numprimes.push_back(1);
			k /= i;
			for(;k % i == 0;k /= i)
				numprimes[numprimes.size() - 1]++;
		}
	}
	bool flag;
	int temp;
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		flag = true;
		cin >> a;
		for(int j = 0; j < primes.size(); j++)
		{
			if(a % primes[j] != 0)
				flag = false;
			else
			{	
				temp = 0;
				for(;a % primes[j] == 0; a /= primes[j])
				{
					temp++;
				}
				if(temp * m < numprimes[j])
					flag = false;
			}
		}
		if(flag)
			sum++;
	}
	cout << sum << endl;

	
}