#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

string s, n;
int co = 0;
string wrongs[6] = {"DCCCC", "LXXXX", "VIIII", "CCCC", "XXXX", "IIII"};


int main()
{
	for(int i = 0; i < 1000; i++)
	{
		int pos;
		cin >> s;
		for(int i = 0; i < 6; i++)
		{
			pos = s.find(wrongs[i]);
			while(pos < 100 && pos >= 0)
			{
				if(i < 3)
					co += 3;
				else
					co += 2;
				s[pos] = 'Q';
				s[pos + 1] = 'Q';
				pos = s.find(wrongs[i]);
			}
		}	
	}
	cout << co << endl;
}