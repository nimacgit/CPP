#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int maxn = 60 * 1000;
const int lim = 1000 * 1000;
long long num[maxn];

int main()
{
	num[0] = 1;
	for(long long i = 1; i < maxn; i++)
		for(long long j = i; j < maxn; j++)
			num[j] = (num[j] + num[j - i]) % lim;
	for(int i = 2; i < maxn; i++)
		if(num[i] == 0)
			cout << i << endl;
}