#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>


using namespace std;

const int maxn = 1000 * 1000 * 10 * 5;
long long sum = 0;
int d[maxn + 2];
const int delta = 12841;
string s;
int a[maxn];

void mab3(int a)
{
	s.clear();
	while(a > 0)
	{
		s.insert(s.begin(), a % 3 + '0');
		a /= 3;
	}
	//cout << s << endl;
}

void dynamic(int a)
{
	int sum1 = 0;
	mab3(a);
	for(int i = 0; i < s.length(); i++)
	{
		d[i] = 1;
		for(int j = i - 1; j >= 0; j--)
		{
			if(s[i] >= s[j])
				d[i] += d[j];
		}
		sum1 = (sum1 + d[i]) % delta;
	}
	d[a] = sum1;
}

int main()
{
	d[1] = 1;
	d[2] = 1;
	d[3] = 2;
	sum = 4;
	for(int i = 4; i <= maxn; i++)
	{
		//cout << i << endl;
		if(int(i / 3) == double(i/3.0))
			d[i] = 2 * d[i / 3];
		else
			dynamic(i);
		sum = (sum + d[i]) % delta;
	}
	cout << sum % delta << endl;
	
}