#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <set>

using namespace std;


const int mo = 648481;
const int maxn = 200000;
vector<long long> p;
bool notp[maxn];
int n = 1e5;


long long pw(int a, int b)
{
	if(b == 0)
		return 1;
	long long po = pw(a, b / 2);
	po = (po*po) % mo;
	if(b % 2)
		return (po * a) % mo;
	return po;
}

void sieve()
{
	for(int i = 2; i < maxn; i++)
	{
		if(!notp[i])
		{
			p.push_back(i);
			for(int j = 2*i; j < maxn; j+=i)
				notp[j] = true;
		}
	}
}

long long getp(long long num, long long pr)
{
	int co = 0;
	long long temp = pr;
	while(temp <= num)
	{
		co += num / temp;
		temp *= pr;
	}
	return co;
}


int main()
{
	sieve();
	long long ans = 1;
	cerr << pw(2, 2) << endl;
	for(int i = 0; i < p.size(); i++)
		ans = (ans * pw(p[i], getp(n, p[i])- 2 * getp(n/2, p[i])))%mo;
	cout << ans << endl;
}
