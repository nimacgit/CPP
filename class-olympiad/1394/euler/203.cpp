#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <set>
#include <math.h>

using namespace std;


const long long maxn = 50;
long long C[maxn + 10][maxn + 10];
set <long long> myset;


long long cn(long long n, long long i)
{
	C[0][0] = 1;
	for(long long j = 1; j <= n; j++)
	{
		C[0][j] = 1; 
		for(long long k = 1; k <= j; k++)
		{
			C[k][j] = C[k - 1][j - 1] + C[k][j - 1];
		}
	}
	return C[i][n];
}

const long long maxnum = cn(50, 25) + 2;
const long long maxprime = 11243249;
vector <long long> prime;
bool notprime[maxprime];

void find()
{
	for(long long i = 2; i < maxprime; i++)
		if(!notprime[i])
		{
			prime.push_back(i * i);
			for(long long j = 2; i * j < maxprime; j++)
				notprime[i * j] = true;
		}

}

bool isok(long long a)
{
	for(long long i = 0; i < prime.size() && prime[i] <= a; i++)
		if(a % prime[i] == 0)
			return false;
	return true;
}


int main()
{
	long long co = 0;
	for(long long i = 1; i <= maxn; i++)
		for(long long j = 1; j <= i / 2; j++)
			myset.insert(cn(i, j));
	find();
	while(!myset.empty())
	{
		if(isok(*(myset.begin())))
		{
			cout << *(myset.begin()) << endl;
			co += *(myset.begin());
		}
		myset.erase(myset.begin());
	}
	cout << co + 1 << endl;
}