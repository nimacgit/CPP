#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;


const int maxn = 16;
int a[maxn] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
int d[maxn];
const int delta = 12569;

int good()
{
	for(int i = 0; i < maxn; i++)
		d[i] = 1;
	for(int i = 1; i < maxn; i++)
	{
		if(a[i] > a[i - 1])
			d[i] = d[i - 1] + 1;

	}
	int maxim = 1;
	for(int i = 0; i < maxn; i++)
		if(d[i] > maxim)
			maxim = d[i];
	return maxim;

}

int main()
{
	int co = 0;
	while(next_permutation(a, a + maxn))
		if(good() == 6)
			co++;
	cout << co % delta << endl;
}