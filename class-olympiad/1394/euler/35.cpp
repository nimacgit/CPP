#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int maxn = 1000 * 1000;
bool mark[maxn + 10];
vector <int> v;

void find()
{
	mark[1] = true;
	for(int i = 2; i < maxn; i++)
	{
		if(!mark[i])
		{
			for(int j = 2; j * i <= maxn; j++)
				mark[i * j] = true;
		}
	}
}

int findm(int i)
{
	int sum = 1;
	while(i > 9)
	{
		sum *= 10;
		i /= 10;
	}
	return sum;
}

bool isok(int i)
{
	int darag = findm(i);
	int temp = i;
	temp = (i % 10) * darag + i / 10;
	while(temp != i)
	{
		if(mark[temp])
			return false;
		temp = (temp % 10) * darag + temp / 10;
	}
	return true;
}

int main()
{
	find();
	int count = 0;
	for(int i = 2; i < maxn; i++)
	{
		if(!mark[i] && isok(i))
			count++;
	}
	cout << count << endl;
}