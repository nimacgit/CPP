#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <set>

using namespace std;

const long long maxn = 100;
bool fil[3][maxn + 100];
int d[3][maxn + 100];
int n, k, t;
int pos;


int main()
{
	cin >> t;
	while(t)
	{
		t--;
		cin >> n >> k;
		for(int j = 0; j < 3; j++)
		{
			string s;
			cin >> s;
			for(int i = 0; i < n; i++)
			{
				if(s[i] == 's')
					pos = j;
				else if(s[i] == '.')
					fil[j][i] = true;
				else
					fil[j][i] = false;
			}
		}
		for(int i = n - 1; i >= 0; i--)
		{
			for(int j = 0; j < 3; j++)
			{	
				if(3*i > n - 1)
					d[j][i] = 1;
				else
				{
					cerr << "asd" << i << endl;
					if(fil[3 * i])
					{
						if(!fil[3 * i + 1])
							d[j][i] = -1;
						else
						{
							if((d[j][i + 1]) == 1 || d[(j + 1) % 3][i + 1] == 1 || d[(j + 2) % 3][i + 1] == 1)
								d[j][i] = 1;
							else
								d[j][i] = 0;
						}
					}
					else
					{
						cerr << " test " << endl;
						d[j][i] = 0;
					}
				}
			}
		}
		cout << endl;
		for(int i = 0; i < 3; i ++)
		{
			for(int j = 0; j < n; j++)
				cerr << d[i][j] << " ";
			cerr << endl;
		}
		if(d[pos][0] == 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	
}