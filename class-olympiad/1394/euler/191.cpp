#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int maxn = 30;
long long ola[maxn + 10];
long long oa[maxn + 10];


int main()
{
	oa[0] = 1;
	oa[1] = 2;
	oa[2] = 4;
	oa[3] = 7;
	for(int i = 4; i <= maxn; i++)
		oa[i] = 2 * oa[i - 1] - oa[i - 4];
	ola[0] = 1;
	ola[1] = 3;
	ola[2] = 8;
	ola[3] = 19;
	for(int i = 4; i <= maxn; i++)
		ola[i] = 2 * ola[i - 1] + oa[i - 1] - oa[i - 4] - ola[i - 4];
	cout << ola[4] << endl;
	cout << ola[maxn] << endl;
}