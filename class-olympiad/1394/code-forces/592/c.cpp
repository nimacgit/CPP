#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <set>

using namespace std;

long long t, b, w;
long long maxim = (5000000000000000000);

long long gcd(long long a, long long b)
{
	if(b == 0)
		return a;
	return gcd(b, a % b);
}

int main()
{
	cin >> t >> w >> b;
	long long tt = t;
	long long gc = gcd(w, b);
	long long tie = 0;
	long long km = w;
	km /= gc;
	if((km * b) < 0)
		tie = min(min(w, b), t);
	else
	{
		tie += ((km * b) / t) * min(w, b);
		t %= (km * b);
		tie += min(min(w, b), t);
	}
	long long sgcd = gcd(tt, tie);
	tie /= sgcd;
	tt /= sgcd;
	cout << tie << "/" << tt << endl;
//	long long rep = 
	
}
