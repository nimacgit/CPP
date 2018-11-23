/*
 * =====================================================================================
 *
 *       Filename:  279-E.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  ۱۵/۱۲/۲۲ ۱۳:۲۰:۴۶
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <bits/stdc++.h>

using namespace std;
string s;
vector<int> mv;
int co = 0;

int main()
{
	cin >> s;
	for(int i = s.length() - 1; i >= 0; i--)
		mv.push_back(s[i] - '0');
	for(int i = 0; i < mv.size(); i++)
	{
		if(mv[i] == 1)
		{
			co++;
			if(i < mv.size() - 1)
				if(mv[i + 1] == 1)
					mv[i+1]++;
		}
		else if(mv[i] == 2)
		{
			if(i == mv.size() - 1)
				co++;
			else
				mv[i + 1]++;
		}
	}
	cout << co << endl;
			
}

