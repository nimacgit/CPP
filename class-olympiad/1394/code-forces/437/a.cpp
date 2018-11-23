#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

string a, b, c, d;
int co = 0;

bool ok(int a, int b, int c, int d)
{
	a-=2;
	b-=2;
	c-=2;
	d-=2;
	if(a >= 2*b && a >= 2*c && a >= 2*d)
		return true;
	if(2*a <= b && 2*a <= c  && 2*a <= d)
		return true;
	return false;
}

int main()
{
	cin >> a >> b >> c >> d;
	if(ok(a.length(), b.length(), c.length(), d.length()))
		co += 1;
	if(ok(b.length(), c.length(), d.length(), a.length()))
		co += 2;
	if(ok(d.length(), c.length(), b.length(), a.length()))
		co += 6;
	if(ok(c.length(), b.length(), d.length(), a.length()))
		co += 10;
	if(co == 1 || co == 2 || co == 6)
		cout << char('A' + co / 2) << endl;
	else
		cout << 'C' << endl;

}
