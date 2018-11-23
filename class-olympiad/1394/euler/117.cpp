#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;



const long long maxn = 1000;
long long d[maxn + 10];
const int maxm = 50;

int main()
{

	d[0] = d[1] = 1;
	d[2] = 2;
	d[3] = 4;
	d[4] = 8;
	for(int i = 5; i <= maxm; i++)
	{
		d[i] = 0;
		d[i] += d[i - 1];
		d[i] += d[i - 2];
		d[i] += d[i - 3];
		d[i] += d[i - 4];
	}
	cout << d[maxm] << endl;
}