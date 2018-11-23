#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <boost/multiprecision/cpp_int.hpp>


using namespace std;
using namespace boost::multiprecision;


const int maxn = 10000;
vector<long long> zeroone;
long long numb;
long long nima;
bool flag = true;
const int maxl = 20;
int one[maxl];
int two[maxl];
int baghi = 0;
string s;
int128_t minim = 0;

void findzeroone(int pos)
{
	if(pos == 16)
	{
		zeroone.push_back(numb);
		return;
	}
	numb *= 10;
	findzeroone(pos + 1);
	numb++;
	findzeroone(pos + 1);
	numb++;
	findzeroone(pos + 1);
	numb /= 10;
	
}


long long f(long long num)
{
	int pos = lower_bound(zeroone.begin(), zeroone.end(), num) - zeroone.begin();
	while(zeroone[pos] % num != 0 && pos < zeroone.size())
		pos++;
	if(zeroone[pos] / num <= 0)
		cout << num << endl;
	return zeroone[pos];
}

void conver()
{
	int128_t nim = 0;
	for(int i = s.length() - 1; i >= 0; i--)
		nim = nim * 10 + s[i] - '0';
	if(minim == 0)
		minim = nim;
	else
		if(nim < minim && nim > 9999)
			minim = nim;
	//cout << nim << endl;
}

void findmin(int pos)
{
	if(pos == maxl)
	{
		if(baghi % 9999 == 0)
		{
			//cout << s << endl;
			conver();
		}
		return;
	}
	s[pos] = '0';
	findmin(pos + 1);
	s[pos] = '1';
	baghi += one[pos];
	findmin(pos + 1);
	baghi -= one[pos];
	s[pos] = '2';
	baghi += two[pos];
	findmin(pos + 1);
	baghi -= two[pos];
}

int main()
{
	numb = 0;
	findzeroone(0);
	sort(zeroone.begin(), zeroone.end());
	long long sum = 0;
	for(long long i = 1; i <= maxn; i++)
		sum += f(i) / i;
	for(int i = 0; i < maxl; i++)
		s += '0';
	nima = 1;
	for(int i = 0; i < maxl ; i++)
	{
		one[i] = (nima % 9999);
		two[i] = (nima * 2) % 9999;
		nima = (nima * 10) % 9999;
	}
	findmin(0);
	cout << sum + minim / 9999 << endl;
}