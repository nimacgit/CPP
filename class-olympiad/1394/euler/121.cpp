#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <boost/multiprecision/cpp_int.hpp>

#define pii pair<int128_t,int128_t>  


using namespace std;
using namespace boost::multiprecision;



const int maxn = 15;
int turn[maxn];

int128_t gcd(int128_t a, int128_t b)
{
	if(b == 0)
		return a;
	return gcd(b, a % b);
}

pii find(int128_t n)
{
	for(int i = 0; i < maxn; i++)
	{
		if(i >= maxn - n)
			turn[i] = 1;
		else
			turn[i] = 0;
	}
	int128_t num = 0, denum = 1;
	do 
	{
		int128_t p = 1, q = 1;
		for(int i = 0; i < maxn; i++)
		{
			q *= (i + 2);
			if(turn[i] == 0)
				p *= (i + 1);
			int128_t gc = gcd(p, q);
			p /= gc;
			q /= gc;
		}
		//cout << " p, q  " << p << "  " << q << endl;
		num = (num * q) + (denum * p);
		denum *= q;
		int128_t temp = gcd(num, denum);
		num /= temp;
		denum /= temp;
		//cout << num << "  " << denum << endl;
	}while(next_permutation(turn, turn + maxn));
	return make_pair(num, denum);
}


int main()
{
	pii temp;
	int128_t num = 0, denum = 1;
	for(int i = maxn / 2 + 1; i < maxn + 1; i++)
	{
		temp = find(i);
		int128_t p = temp.first, q = temp.second;
		cout << p << "  " << q << endl;
		num = num * q + denum * p;
		denum *= q;
		int128_t gc = gcd(num, denum);
		num /= gc;
		denum /= gc;
	}
	cout << num << "  " << denum << endl;
	cout << denum / num << endl;
}