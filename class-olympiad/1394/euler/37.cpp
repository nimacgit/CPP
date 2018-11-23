#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int maxn = 1000 * 1000 * 10;
vector <int> v;
int mark[maxn + 10];
void find()
{
	mark[1] = true;
	for(int i = 2; i < maxn; i++)
	{
		if(!mark[i])
		{
			v.push_back(i);
			for(int j = 2; j * i < maxn; j++)
				mark[i * j] = true;
		}
	}
}

bool isok(int i)
{
	int temp = i;
	int dah = 1;
	while(temp)
	{
		if(mark[temp])
			return false;
		temp /= 10;
		dah *= 10;
	}
	dah /= 10;
	while(dah)
	{
		if(mark[i % dah])
			return false;
		dah /= 10;
	}
	return true;
}

int main()
{
	long long sum = 0;
	find();
	for(int i = 4; i < v.size(); i++)
	{
		if(isok(v[i]))
		{
			cout << v[i] << endl;
			sum += v[i];
		}
	}
	cout << sum << endl;
}