#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <set>

using namespace std;


const int maxn  = 8;
string s[8];

int main()
{
	for(int i = 0; i < maxn; i++)
		cin >> s[i];
	bool fa = false, fb = false;
	int a = 1000, b = 1000;
	
	for(int i = 0; i < maxn; i++)
	{
		for(int j = 0; j < maxn; j++)
		{
			if(s[i][j] == 'W' && !fa)
			{
				fa = true;
				a = i;
				for(int k = i; k >= 0; k--)
				{
					if(s[k][j] == 'B')
					{
						fa = false;
						a = 1000;
					}
				}

			}
			else if(s[i][j] == 'B')
			{
				fb = true;
				int temp = b;
				b = maxn - i - 1;
				for(int k = i; k >= 0; k--)
				{
					if(s[k][j] == 'W')
					{
						fb = false;
						b = 1000;
					}
				}
				if(b == 1000)
					b = temp;
				
			}
		}
	}
	if(b < a)
		cout << 'B' << endl;
	else
		cout << 'A' << endl;
}
