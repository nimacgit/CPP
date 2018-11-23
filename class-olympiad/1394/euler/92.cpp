#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int maxn = 10 * 1000 * 1000;

int d[maxn * 30];
bool mark[maxn * 30];

int dynamic(int n)
{
	if(!mark[n])
	{
		int sum = 0;
		while(n)
		{
			sum += ((n % 10) *(n % 10));
			n /= 10;
		}
		d[n] = dynamic(sum);
		mark[n] = true;
		return d[n];
	}
	return d[n];
}

int main()
{
	int counter = 1;
	mark[1] = mark[89] = true;
	d[1] = 1;
	d[89] = 89;
	for(int i = 2; i < maxn; i++)
	{
		if(dynamic(i) == 89)
			counter++;
	}
	cout << counter << endl;
}