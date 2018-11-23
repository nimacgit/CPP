#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;


const int maxm = 50;
const int maxn = 1000 * 1000 * 100;
long long d[maxn + 10];

int main()
{
	for(int i = 0; i < maxm; i++)
		d[i] = 1;
	d[maxm] = 2;
	for(int i = maxm + 1; 2 ; i++)
	{
		d[i] = 1;
		d[i] += d[i - 1];
		for(int j = i - maxm - 1; j >= 0; j--)
			d[i] += d[j];
		if(d[i] > 1000 * 1000)
		{
			cout << i << "  " << d[i] << endl;
			return 0;
		}
	}
	/*use[maxn] = use[maxn + 1] = use[maxn - 1] = use[maxn - 2] = true;
	d[maxn] = d[maxn + 1] = d[maxn - 1] = d[maxn - 2] = 1;
	cout << find(1) << endl;
	*/
}