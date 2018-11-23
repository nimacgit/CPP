#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;


int a[8] = {1,2,3,4,5,6,7,8};
int d[8];
const int delta = 12569;

int good()
{
	for(int i = 0; i < 8; i++)
		d[i] = 1;
	for(int i = 1; i < 8; i++)
	{
		if(a[i] > a[i - 1])
			d[i] = d[i - 1] + 1;

	}
	int maxim = 1;
	for(int i = 0; i < 8; i++)
		if(d[i] > maxim)
			maxim = d[i];
	return maxim;

}

int main()
{
	int co = 0;
	while(next_permutation(a, a + 8))
		if(good() == 4)
			co++;
	cout << co % delta << endl;
}