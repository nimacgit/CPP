#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>


using namespace std;

string s;
const int maxn = 1000 * 10;
int d[10];
const int delta = 12841;
int a[maxn];
long long sum = 0;
int temp = 3;

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
		sum1 = (sum1 + d[i]) /* % delta */;
	}
	sum = (sum + sum1) /* % delta */;
	if(a == temp - 1)
	{
		temp *= 3;
		cerr << sum << endl;
	}
	//cout << a << " " <<  sum1 << endl;

}

int main()
{
	for(int i = 1; i <= maxn; i++)
		dynamic(i);
	cout << sum << endl;
	
}