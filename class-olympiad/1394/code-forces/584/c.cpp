#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>


using namespace std;

int n, t;
string s[3];
int co = 0;
int pos = 0;

int main()
{
	cin >> n >> t;
	t *= 2;
	cin >> s[0] >> s[1];
	for(int i = 0; i < n; i++)
	{
		if(s[0][i] != s[1][i])
			co++;
	}
	if((t == 0 && co != 0) || (t < co))
	{
		cout << -1 << endl;
		return 0;
	}
	else
	{
		if(t == 0 && co == 0)
		{
			cout << s[0] << endl;
			return 0;
		}
		else
		{
			for(int i = 0; i < n; i++)
			{
				if(s[0][i] == s[1][i])
				{
					if(t > co + 1)
					{
						if(s[0][i] == 'a')
							s[2] += 'b';
						else
							s[2] += 'a';
						t -= 2;
					}
					else
						s[2] += s[0][i];
				}
				else
				{
					if(t > co)
					{
						char c = 'a';
						while(s[0][i] == c || s[1][i] == c)
							c++;
						s[2] += c;
						t -= 2;
					}
					else
					{
						s[2] += s[pos][i];
						pos = (pos + 1) % 2;
						t--;
					}
					co--;
				}
			}
		}
	}
	cout << s[2] << endl;
}