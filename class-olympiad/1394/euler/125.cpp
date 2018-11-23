#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <list>
using namespace std;

const int maxnum = 1000 * 1000 * 100;
const int maxn = 1000 * 10;
int d[maxn + 10];
bool num[maxnum + 1];
list <int> myset;

void find()
{
	for(int i = 0; i < maxn + 5; i++)
		d[i] = i * i;
}

bool ispoli(int a)
{
	int temp = a;
	int b = 0;
	while(temp)
	{
		b = b * 10 + temp % 10;
		temp /= 10;
	}
	if(a == b)
		return true;
	return false;
}

long long findlen(int len)
{
	long long sum = 0;
	long long sumcor = 0;
	int start = 1;
	int end = len + 1;
	for(int i = start; i < end; i++)
		sum += d[i];
	if(ispoli(sum) && sum <= maxnum)
		num[sum] = true;
	while(end <= maxn && sum <= maxnum)
	{
		sum -= d[start];
		start++;
		sum += d[end];
		end++;
		if(sum <= maxnum)
			if(ispoli(sum))
				num[sum] = true;
	}
}

int main()
{
	long long sum = 0;
	find();
	for(int i = 2; i <= maxn; i++)
		findlen(i);
	for(int i = 1; i <= maxnum; i++)
		if(num[i])
			sum += i;
	cout << sum << endl;
}