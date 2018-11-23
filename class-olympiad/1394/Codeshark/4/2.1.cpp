#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

long long a = 1e17;
long long mo =  55117, pmo = 55116;
long long pow(long long a, long long p)
{
	if(p == 1)
		return a;
	if(p % 2 == 1)
		return ((((a * pow(a, p / 2)) % mo)* pow(a, p / 2)) % mo);
	return (pow(a, p/2) * pow(a, p/2)) % mo;
}


int main()
{
	a *= 5;
	a += 1;
	long long ans = (a % mo) * (((a - 1) / 2) % mo) % mo;
	cerr << a << endl;
		
	long long pp = (a % pmo) * (((a-1)/2) % pmo) % pmo;
	cout << pow(ans, pp)%mo << endl;
}
