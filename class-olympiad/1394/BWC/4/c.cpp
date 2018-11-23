/*
 * =====================================================================================
 *
 *       Filename:  c.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  ۱۵/۱۰/۳۰ ۱۹:۵۷:۰۰
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

bool found[10];
string s1, s2;
int ram[10];
long long num = 0;
int delta = 648481;
bool isnot[10][10];

int main()
{
	for(int i = 0; i < 50; i++)
	{
		cin >> s1 >> s2;
		for(int j = 0; j < 10; j++)
		{
			if(s2[j] == '1')
			{
				found[j] = true;
				ram[j] = s1[j] - '0';
			}
			else
			{
				isnot[j][s1[j] - '0'] = true;
			}
		}
	}
	
	for(int i = 0; i < 10; i++)
	{
		if(!found[i]){
		for(int j = 0; j < 10; j++)
		{
			if(!isnot[i][j])
			{
				cout << i << "  " << j << endl;
				ram[i] = j;
			}
		}
		}
	}
	cout << ram[0] << endl;
	for(int i = 0; i < 10; i++)
	{
		cout << i << " " << ram[i] << endl;
		num *= 10;
		num += ram[i];
	}
	cout << num % delta << endl;
}

