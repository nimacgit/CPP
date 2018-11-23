#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <set>

using namespace std;

const int delta = 46639;
const int maxn = delta;

int gc(int a, int b)
{
	if(b == 0)
		return a;
	return gc(b , a % b);
}

int main()
{
	string s;
	for(int a = maxn; a > 0; a /= 2)
		s += (a % 2 + '0');
	reverse(s.begin(), s.begin() + s.length());
	cout << s << " " << s.length() << endl;
	int sum = 1;
	for(int i = s.length(); i > 0; i--)
		sum *= 2;
	cout << sum - 1 << endl;
	//ans = 1023, 0;
}