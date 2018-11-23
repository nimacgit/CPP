#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int delta = 229939;
int facts[delta];
bool notprime[delta];
vector<int> primes;
vector <int> goodfact;

void findfact()
{
	for(int i = 1; i < delta; i++)
	{
		for(int j = 2; j * i < delta; j++)
			facts[i * j]++;
	}
}

void find()
{
	for(int i = 2; i <= delta/goodfact[0]; i++)
	{
		if(!notprime[i])
		{
			primes.push_back(i);
			for(int j = 2; j * i <= delta / goodfact[0]; j++)
				notprime[i * j] = true;
		}
	}
}

int main()
{
	findfact();
	for(int i = 1; i < delta; i++)
		if(facts[i] == 48)
			goodfact.push_back(i);
	cout << goodfact.size() << endl;
	cout << goodfact[0] << endl;
	find();
	cout << primes.size() << endl;

}