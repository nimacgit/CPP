#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>


using namespace std;

int n;
const int maxn = 1000*10000, maxp = 1000*1000;
vector<long long> p;
long long pr[maxp];
bool notp[maxn];
int mo = 648481;
int maxmo = 1e9 + 7;

long long A()
{
	long long ans = 1, fans = 0;
	for(int i = 1; i <= n; i++)
	{
		int temp = i;
		for(int j = 0; j < p.size() && temp > 1; j++)
		{
			if(temp % p[j] == 0)
			{
				long long co = 0;
				while(temp % p[j] == 0)
				{
					temp /= p[j];
					co++;
				}
				for(int i = pr[j]; i < max(pr[j], co); i++)
					ans = (ans * p[j]) % maxmo;
				pr[j] = max(pr[j], co);
			}
		}
		fans = (fans + ans) % mo;
	}
	return fans;
}

void sieve()
{
	for(int i = 2; i < maxn; i++)
	{
		if(!notp[i])
		{
			p.push_back(i);
			for(int j = 2; j * i < maxn; j++)
				notp[i * j] = true;
		}
	}
}



int main()
{
	sieve();
	n = 1000000;
	long long temp = A();
	cout << temp % mo << endl;
}
