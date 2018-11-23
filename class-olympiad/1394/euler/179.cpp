#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int maxn = 1000 * 1000 * 10;
long long d[maxn + 10];

int main()
{
	int co = 0;
	for(int i = 1; i < maxn; i++)	
		for(int j = 1; j * i < maxn; j++)
			d[i * j]++;
	for(int i = 1; i < maxn; i++)
		if(d[i] == d[i + 1])
			co++;
	cout << co << endl;
}