#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <set>
#include <bits/stdc++.h>
#define S second
#define F first


using namespace std;


const int mo = 648481;
long long n = 1;
long long r = 500;


long long pw(long long a, long long b)
{
	if(b == 0)
		return 1;
	long long po = pw(a, b / 2);
	po = (po*po) % mo;
	if(b % 2)
		return (po * a) % mo;
	return po;
}

vector<long long> fact(long long n)
{
	vector<long long> temp;
	for(long long i = 2; i * i <= n; i++)
	{
		while(n % i == 0)
		{
			n /= i;
			temp.push_back(i);
		}
	}
	if(n > 1)
		temp.push_back(n);
	return temp;
}



int main()
{
	for(int i = 0; i < 11; i++)
		n *= (long long)10;
	map<long long, int> m;
	for(long long i = n - r + 1; i <= n; i++)
	{
		vector<long long> p = fact(i);
		for(long long pr : p)
			m[pr]++;
	}
	for(long long i = 2; i <= r; i++)
	{
		vector<long long>p = fact(i);
		for(long long pr : p)
			m[pr]--;
	}
	long long ans = 1;
	for(auto x: m)
		ans = (ans * pw(x.F, x.S)) % mo;
	cout << ans << endl;
}
