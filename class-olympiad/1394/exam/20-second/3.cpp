#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int maxn = 1389000;
bool notprime[maxn + 3];
string s;

void pluss(string a)
{
	reverse(a.begin(), a.end());
	a[0]++;
	for(int i = 0; a[i] > '9'; i++)
	{
		a[i] = '0';
		if(i == s.length() - 1)
			a += '1';
		else
			a[i + 1]++;
	}
	reverse(a.begin(), a.end());
	s = a;
}

bool isprime()
{
	notprime[1] = true;
	for(int i = 2; i <= maxn; i++)
	{
		if(!notprime[i])
		{
			for(int j = 2; j * i <= maxn; j++)
				notprime[i * j] = true;
		}
	}
}

int find1(string a)
{
	int sum = 0;
	for(int i = 0; i < a.length(); i++)
	{
		if(!notprime[atoi(a.substr(i, 1).c_str())])
			sum++;
		if(i + 1 < a.length())
		{
			if(!notprime[atoi(a.substr(i, 2).c_str())])
				sum++;
		}
		if(i + 2 < a.length())
		{
			if(!notprime[atoi(a.substr(i, 3).c_str())])
				sum++;
		}
		if(i + 3 < a.length())
		{
			if(!notprime[atoi(a.substr(i, 4).c_str())])
				sum++;
		}
		if(i + 4 < a.length())
		{
			if(!notprime[atoi(a.substr(i, 5).c_str())])
				sum++;
		}
		if(i + 5 < a.length())
		{
			if(!notprime[atoi(a.substr(i, 6).c_str())])
				sum++;
		}
		if(i + 6 < a.length())
		{
			if(!notprime[atoi(a.substr(i, 7).c_str())])
				sum++;
		}
	}
	return sum;
}


int main()
{
	s = '1';
	isprime();
	long long sum1 = 0;
	for(int i = 1; i <= maxn; i++)
	{
		sum1 += find1(s);
		pluss(s);
	}
	cout << sum1 << endl;

}