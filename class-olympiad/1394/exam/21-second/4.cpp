#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>


using namespace std;


const int maxn = 100 * 1000 * 1000;
int NumberFactor[maxn + 10];
const int delta = 28813;


void findprime()
{
	for(int i = 2; i < maxn; i++)
	{
		if(NumberFactor[i] == 0)
		{
			NumberFactor[i]++;
			for(int j = 2; j * i < maxn; j++)
				NumberFactor[i * j]++;
		}
	}
}


int main()
{
	findprime();
	long long sum = 0;
	for(int i = 2; i < maxn; i++)
		if(i % 10 == NumberFactor[i])
			sum = (sum + i) % delta;
	cout << sum << endl;
}