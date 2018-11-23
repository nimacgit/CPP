#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int delta = 229939;
bool notprime[delta];
vector <int> factor[delta];

void find()
{
	for(int i = 2; i < delta; i++)
	{
		if(!notprime[i])
		{
			factor[i].push_back(i);
			for(int j = 2; j * i < delta; j++)
			{
				notprime[i * j] = true;
				factor[i * j].push_back(i);
			}
		}
	}
}

int phi(int a)
{
	int p = a;
	for(int i = 0; i < factor[a].size(); i++)
	{
		p *= (factor[a][i] - 1);
		p /= factor[a][i];
	}
}

int main()
{
	find();
	long long sum = 0;
	for(int i = 2; i < delta; i++)
		sum += phi(i);

}