#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>

using namespace std;

const int maxn = 1000 * 1000;
bool mark[maxn];
vector<int> v;

void find()
{
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

bool isok(int a)
{
	for(int i = 0; v[i] < a; i++)
	{
		int temp = a - v[i];
		if(temp % 2 == 0)
			if(double(sqrt(temp / 2)) == int(sqrt(temp / 2)))
				return true;
	}
	return false;
}

int main()
{
	find();
	for(int i = 9; i < maxn; i+= 2)
		if(mark[i])
			if(!isok(i))
			{
				cout << i << endl;
				return 0;
			}



}