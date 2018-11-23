#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;


const long long maxn = 50;
long long d[maxn + 10];

int main()
{

	d[1] = d[0] = d[2] = 1;
	d[3] = 2;
	for(int i = 4; i <= maxn; i++)
	{
		d[i] = 1;
		d[i] += d[i - 1];
		for(int j = i - 4; j >= 0; j--)
			d[i] += d[j];
	}
	cout << d[maxn] << endl;
	/*use[maxn] = use[maxn + 1] = use[maxn - 1] = use[maxn - 2] = true;
	d[maxn] = d[maxn + 1] = d[maxn - 1] = d[maxn - 2] = 1;
	cout << find(1) << endl;
	*/
}