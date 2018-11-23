#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <algorithm>



using namespace std;

string s, b;



int main()
{
	cin >> s;
	bool flag;
	for(int i = 0; i < s.length(); i++)
	{
		flag = false;
		if(i < s.length() - 3)
		{
			if(s[i] == s[i + 1] && (s[i + 1] == s[i + 2]))
			{
				while(s[i] == s[i + 1] && (s[i + 1] == s[i + 2]))
				flag = true;
			}
			else if(s[i] == s[i + 1] && s[i + 2] == s[i + 3])
				s.erase(s.begin() + i + 2);

		}
		else if(i < s.length() - 2)
			if(s[i] == s[i + 1] && s[i + 1] == s[i + 2])
				s.erase(s.begin() + i + 2);
		if(!flag)
			b += s[i];
	}
	cout << b << endl;


}