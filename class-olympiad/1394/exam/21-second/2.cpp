#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>


using namespace std;

const int maxn = 81;
const int delta = 28813;
bool asleep[maxn];
int sleep = 0;

void reset()
{
	for(int i = 0; i < maxn; i++)
		asleep[i] = false;
	sleep = 0;
}

int makesleep(int a)
{
	int i = 23;
	while(i)
	{
		a = (a + 1) % 81;
		if(!asleep[a])
			i--;
	}
	asleep[a] = true;
	sleep++;
	return a;
}

int main()
{
	int start;
	for(int i = 0; i < maxn; i++)
	{
		//cout << i << endl;
		reset();
		sleep = 1;
		asleep[i] = true;
		start = i;
		while(sleep < 80)
			start = makesleep(start);
		for(int j = 0; j < maxn; j++)
			if(!asleep[j])
				if(j == 52)
				{
					cout << i << endl;
					return 0;
				}
	}
}