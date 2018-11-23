#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int maxn = 1000 * 1000;
const int maxk = 4;
vector<int> numberprime[maxk];
int markprime[maxk][maxn];
vector<int> primes;
bool check[maxn];

void find()
{
	for(int i = 2; i < maxn; i++)
	{
		if(!check[i])
		{
			primes.push_back(i);
			for(int j = 2; j * i < maxn; j++)
				check[i * j] = true;
		}
	}
}

int main()
{
	int num1;
	find();
	for(int i = 5; i < maxn; i++)
	{
		if(check[i] && check[i + 1] && check[i + 2] && check[i + 3])
		{
			bool flag = true;
			for(int j = 0; j < maxk; j++)
			{
				for(int l = 0; l < numberprime[j].size(); l++)
					markprime[j][numberprime[j][l]] = 0;
				numberprime[j].clear();
			}
			for(int j = 0; j < maxk && flag; j++)
			{
				num1 = i + j;
				for(int l = 0; l < primes.size(); l++)
				{
					if(num1 % primes[l] == 0)
					{
						numberprime[j].push_back(primes[l]);
						while(num1 % primes[l] == 0)
						{
							num1 /= primes[l];
							markprime[j][primes[l]]++;

						}
					}
				}
				if(numberprime[j].size() != 4)
					flag = false;
			}
			if(flag)
			{
				cout << i << endl;
				return 0;
			}
		}
	}
}