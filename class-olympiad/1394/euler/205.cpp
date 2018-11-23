#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;


long long first[37] , second[37];
long long sum = 0, win = 0;
long long a[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
long long b[6] = {1, 1, 1, 1, 1, 1};
bool flaga = true, flagb = true;

void plusa()
{
	a[8]++;
	long long i = 8;
	while(i > 0 && a[i] > 4)
	{
		a[i] -= 4;
		a[i - 1]++;
		i--;
		if(a[0] > 4)
			flaga = false;
	}
}
long long suma()
{
	long long c = 0;
	for(long long i = 0; i < 9; i++)
		c += a[i];
	return c;
}

void plusb()
{
	b[5]++;
	long long i = 5;
	while(i > 0 && b[i] > 6)
	{
		b[i] -= 6;
		b[i - 1]++;
		i--;
		if(b[0] > 6)
			flagb = false;
	}
}
long long sumb()
{
	long long c = 0;
	for(long long i = 0; i < 6; i++)
		c += b[i];
	return c;
}

int main()
{
	while(flaga)
	{
		first[suma()]++;
		plusa();
	}
	while(flagb)
	{
		second[sumb()]++;
		plusb();
	}
	long long temp = 0;
	for(long long i = 2; i < 37; i++)
	{
		temp += second[i - 1];
		win += first[i] * temp;
	}
	temp += second[36];
	for(long long i = 1; i < 37; i++)
		sum += first[i];
	sum = sum * temp;
	cout << sum << "   " << win << endl;
	cout << double(win) / double(sum) << endl;

}