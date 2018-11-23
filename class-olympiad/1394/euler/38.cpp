#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

long long checkout[10];
const long long maxn = 1000 * 1000 * 1000;

bool change(long long  a)
{
	long long bagh;
	while(a > 0)
	{
		bagh = a % 10;
		if(checkout[bagh] == 0 && bagh != 0)
			checkout[bagh]++;
		else
			return false;
		a /= 10;
	}
	return true;
}

bool check()
{
	for(long long i = 1; i < 10; i++)
	{
		if(checkout[i] == 0)
			return false;
	}
	return true;
}
void reset()
{
	for(long long i = 0; i < 10; i++)
		checkout[i] = 0;
}


int main()
{
	long long maxim = 0;
	long long n = 8;
	reset();
	for(;n > 5; n--)
	{
		for(long long i = 1; i < 10; i++)
		{
			bool flag = true;
			long long num = 0;
			reset();
			for(long long j = 1; j <= n; j++)
			{
				for(int temp = i * j; temp > 0; temp /= 10)
					num *= 10;
				num += (i * j);
			}
			flag = (flag && change(num));
			if(flag)
			{
				flag = (flag && check());
			}
			if(flag)
			{
				if(num > maxim)
					maxim = num;
			}	
		}
	}
	for(long long i = 1; i < 100; i++)
	{
		bool flag = true;
		long long num = 0;
		reset();
		for(long long j = 1; j <= n; j++)
		{
			for(int temp = i * j; temp > 0; temp /= 10)
				num *= 10;
			num += (i * j);
		}
		flag = (flag && change(num));
		if(flag)
		{
			flag = (flag && check());
		}
		if(flag)
		{
			if(num > maxim)
				maxim = num;
		}	
	}
	n--;
	for(long long i = 1; i < 100; i++)
	{
		bool flag = true;
		long long num = 0;
		reset();
		for(long long j = 1; j <= n; j++)
		{
			for(int temp = i * j; temp > 0; temp /= 10)
				num *= 10;
			num += (i * j);
		}
		flag = (flag && change(num));
		if(flag)
		{
			flag = (flag && check());
		}
		if(flag)
		{
			if(num > maxim)
				maxim = num;
		}	
	}
	n--;
	for(long long i = 1; i < 1000; i++)
	{
		bool flag = true;
		long long num = 0;
		reset();
		for(long long j = 1; j <= n; j++)
		{
			for(int temp = i * j; temp > 0; temp /= 10)
				num *= 10;
			num += (i * j);
		}
		flag = (flag && change(num));
		if(flag)
		{
			flag = (flag && check());
		}
		if(flag)
		{
			if(num > maxim)
				maxim = num;
		}	
	}
	n--;
	for(long long i = 1; i < 10000; i++)
	{
		bool flag = true;
		long long num = 0;
		reset();
		for(long long j = 1; j <= n; j++)
		{
			for(int temp = i * j; temp > 0; temp /= 10)
				num *= 10;
			num += (i * j);
		}
		flag = (flag && change(num));
		if(flag)
		{
			flag = (flag && check());
		}
		if(flag)
		{
			if(num > maxim)
				maxim = num;
		}	
	}
	cout << maxim << endl;

}