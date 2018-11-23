/*
 * =====================================================================================
 *
 *       Filename:  b.cpp
 *
 *    Description:  i
 *
 *        Version:  1.0
 *        Created:  ۱۵/۱۰/۳۰ ۱۹:۳۷:۳۲
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

const int maxn = 1394 * 1394;
bool seen[maxn + 100];
int delta = 648481;
int co = 1;

int main()
{
	for(int i = 2; i < maxn; i++)
	{
		if(!seen[i])
		{
			for(int j = 1; j * i <= maxn; j++)
			{
				if(!seen[i * j])
		{		
		co++;			
				seen[i * j] = true;
				if(co == maxn - (delta % 1000))
				{
					cout << i * j << endl;
				}
				}
			}
		}
	}
}
