#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <set>

using namespace std;

const int maxn = 1000 * 1000;
vector <long long> prime;
bool mark[maxn];
const long long maximum = 50 * 1000 * 1000;
set <long long> mysets;

void find()
{
	for(int i = 2; i < maxn ; i++)
	{
		if(!mark[i])
		{
			prime.push_back(i);
			for(int j = 2; j * i < maxn; j++)
				mark[i * j] = true;
			
		}
	}
}

int main()
{
	find();
	bool flag1 = true, flag2 = true, flag3 = true;;
	long long temp1, temp2, temp3;
	for(int i = 0; i < prime.size() && flag1; i++)
	{
		temp1 = prime[i] * prime[i] * prime[i] * prime[i];
		if(temp1 > maximum)
			flag1 = false;
		flag2 = true;
		for(int j = 0; j < prime.size() && flag2 && flag1; j++)
		{
			temp2 = prime[j] * prime[j] * prime[j];
			if(temp2 > maximum || temp2 + temp1 > maximum)
				flag2 = false;
			flag3 = true;
			for(int l = 0; l < prime.size() && flag1 && flag2 && flag3; l++)
			{
				temp3 = prime[l] * prime[l];
				if(temp3 > maximum)
					flag3 = false;
				if(temp3 + temp2 + temp1 < maximum)
					mysets.insert(temp3 + temp2 + temp1);
				else
					flag3 = false;

			}
		}
	}
	cout << mysets.size() << endl;
}