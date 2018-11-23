#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <set>

using namespace std;

const int maxn = 11;
string s;
set <string> goods;

void make(int pos)
{
	if(pos == s.length())
	{
		reverse(s.begin(), s.end());
		goods.insert(s);
		reverse(s.begin(), s.end());
		return;
	}
	cout << pos << "   " << s << "  ";
	reverse(s.begin(), s.begin() + pos + 1);
	cout << s << endl;
	for(int i = 1; i < pos; i++)
	{
		reverse(s.begin(), s.begin() + i + 1);
		make(pos + 1);
		reverse(s.begin(), s.begin() + i + 1);
	}
	reverse(s.begin(), s.begin() + pos + 1);
}


int main()
{
	char c = 'K';
	for(int i = 0; i < maxn; i++)
	{
		s += c;
		c--;
	}
	cout << s << endl;
	swap(s[0], s[1]);
	make(2);
	cout << goods.size() << endl;
	for(int i = 1; i < 2011; i++)
		goods.erase(goods.begin());
	cout << *(goods.begin()) << endl;
}