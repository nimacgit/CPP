#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <set>

using namespace std;

const int maxn = 26;
int n, m;
string s;
char ch[maxn];

int main()
{
	for(int i = 0; i < 26; i++)
		ch[i] = i + 'a';
	cin >> n >> m;
	cin >> s;
	for(int i = 0; i < m; i++)
	{
		char x, y;
		cin >> x >> y;
		for(int i = 0; i < 26; i++)
			if(ch[i] == x)
				ch[i] = y;
			else if(ch[i] == y)
				ch[i] = x;
	}
	for(int i = 0; i < n; i++)
		s[i] = ch[s[i] - 'a'];
	cout << s << endl;


	
}
