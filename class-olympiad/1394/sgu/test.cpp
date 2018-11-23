#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <list>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>



using namespace std;

string s;
vector <bool> b;

int main()
{
	cin >> s;
	int n = s.length();
	for(int i = 0; i < n; i++)
	{
		if(s[i] == '(')
			b.push_back(0);
		else
			b.push_back(1);
	}
}