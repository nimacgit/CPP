#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>


using namespace std;

const int delta = 29123;
bool notprime[ 2 * delta + 3];
vector<int> primes;
vector<int> v, v1;


int D(int a, int b)
{
	v.clear();
	v1.clear();
	while(a != 0 || b != 0)
	{
		if(a > 0)
			v1.insert(v1.begin(), a);
		if(b > 0)
			v.insert(v.begin(), b);
		a = a / 2;
		b = b / 2;
	}
	while(v[0] == v1[0])
	{
		v1.erase(v1.begin());
		v.erase(v.begin());
	}
	return v1.size() + v.size();
}


int main()
{
	long long sum = 1;
	for(int i = 2; i <= 2 * delta; i++)
	{
		if(!notprime[i])
		{
			primes.push_back(i);
			for(int j = 2; j * i <= 2 * delta; j++)
				notprime[i * j] = true;
		}
	}
	for(int i = 0; i < primes.size(); i++)
	{
		for(int j = i + 1; j < primes.size(); j++)
		{
			//cout << " be " << i << "  " << j << endl;
			sum = (sum * D(primes[i], primes[j]) )% delta;
		}
	}
	cout << sum << endl;

}