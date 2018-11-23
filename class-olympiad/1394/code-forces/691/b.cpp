#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

string s;
bool isok(char a, char b)
{
	if((a == 'b' && b == 'd') || (a == 'd' && b == 'b' ) || (a == 'p' && b == 'q') || (a == 'q' && b =='p'))
		return true;
	if(a == b)
		if(a == 'H' || a == 'x' || a == 'X' || a == 'T'  || a == 'v' || a == 'V' || a == 'Y' || a == 'o' || a == 'O' || a == 'M' || a == 'I' || a == 'A' || a == 'U' || a == 'w' || a == 'W')
				return true;
	return false;

}
int main()
{
	cin >> s;
	for(int i = 0; i < s.length() / 2; i++)
		if(!isok(s[i] , s[s.length() - 1 - i]))
		{
			cout << "NIE" << endl;
			return 0;
		}
	if(s.length() % 2 == 1)
	{
		if(!isok(s[s.length()/2], s[s.length()/2]))
		{
			cout << "NIE" << endl;
			return 0;
		}
	}
	cout << "TAK" << endl;
}
