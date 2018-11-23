#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <list>
using namespace std;

list <unsigned long long> mylist;

bool isok(unsigned long long a, unsigned long long b)
{
	unsigned long long sum = 0;
	while(a)
	{
		sum += a % 10;
		a /= 10;
	}
	if(sum == b)
		return true;
	return false;
}
void find()
{
	for(int i = 1; i < 1000; i++)
	{
		unsigned long long temp = i;
		for(int j = 1; j < 100; j++)
		{
			if(temp > 99)
				if(isok(temp, i))
					mylist.push_back(temp);
			temp *= i;
		}
	}
}


int main()
{
	find();
	cout << mylist.size() << endl;
	mylist.sort();
	for(int i = 0; i < 30; i++)
	{
		cout << i + 1 << endl;
		cout << mylist.front() << endl;
		mylist.pop_front();
	}
}