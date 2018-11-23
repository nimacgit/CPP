#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int maxn = 1000 * 1000 * 50;
vector <int> primes;
int a[20] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
const long long num = 15499;
const long long denum = 94744;

int main()
{
	for(int i = 0; i < 12; i++)
		primes.push_back(a[i]);
	int s = 1 , p = 1;
	for(int i = 0; i < primes.size(); i++)
	{
		s *= primes[i];
		p *= (primes[i] - 1);
		for(int j = 2; j <= primes[i]; j++)
		{
			if(p * j * denum < ((s * j) - 1) * num)
			{
				cout << s * j << endl;
				return 0;
			}
		}
	}
	
}

