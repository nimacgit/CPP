#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <set>
#define show(x) cerr << #x << "  " << x << endl;
using namespace std;

int n, r;
int p = 0;
int num = 1000 * 1000 * 1000, divis = 0;
set <int> myset;
string s;
char c = 'S';

void change()
{
	if(c == 'T')
		c = 'B';
	else
		c = 'T';
}

void gcd(int a, int b)
{
	myset.insert(a);
	if(b == 0)
		return;
	if(a >= b)
		p += a / b;
	gcd(b, a % b);
}

void print(int a, int b)
{
	if(b == 0)
		return;
	for(int i = 0; i < a / b; i++)
		s += c;
	change();
	print(b, a % b);
}

int main()
{
	cin >> n >> r;
	for(int i = 1; i <= r; i++)
	{
		p = 0;
		myset.clear();
		gcd(r, i);
		if(p == n && *myset.begin() == 1)
		{
			if(divis < myset.size())
			{
				num = i;
				divis = myset.size();
			}
		}
	}
	if(num == 1000 * 1000 * 1000)
	{
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	//cerr << num << "  " << divis << endl;
	cout << n - divis << endl;



	if(divis % 2 == 0)
		c = 'B';
	else
		c = 'T';
	print(r, num);
	reverse(s.begin(), s.begin() + s.length());
	s[0] = 'T';
	cout << s << endl;
	return 0;

}