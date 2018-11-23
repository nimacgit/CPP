#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

vector <int> v;
const int maxn = 1000 * 1000;
bool ispal10(int a)
{
	int temp = a;
	int b = 0;
	while(temp > 0)
	{
		b = b * 10 + temp % 10;
		temp /= 10;
	}
	if(b == a)
		return true;
	return false;
}

void makebin(int a)
{
	v.clear();
	while(a > 0)
	{
		v.push_back(a % 2);
		a /= 2;
	}
}

bool isok2()
{
	for(int i = 0; i < v.size(); i++)
	{
		if(v[i] != v[v.size() - 1 - i])
			return false;
	}
	return true;
}

int main()
{
	long long sum = 0;
	for(int i = 0; i < maxn; i++)
	{
		if(ispal10(i))
		{
			makebin(i);
			if(isok2())
				sum += i;
		}
	}
	cout << sum << endl;
}