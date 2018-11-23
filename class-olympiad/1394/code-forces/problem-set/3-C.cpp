#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>


using namespace std;

string s[3];
int x = 0, o = 0, firs[3], seco[3];
int fir, sec;

int main()
{

	cin >> s[0] >> s[1] >> s[2];
	for(int i = 0; i < 3; i++)
	{
		firs[i] = seco[i] = 0;
		for(int j = 0; j < 3; j++)
		{
			if(s[i][j] == 'X')
				x++;
			else if(s[i][j] == '0')
				o++;
		}
	}
	cerr << x << "  " << o << endl;
	if(!(x==o || x == o + 1))
	{
		cout << "illegal" << endl;
		return 0;
	}
	if(s[0][0] == s[1][1] && s[1][1] == s[2][2])
	{
		if(s[0][0] == 'X')
		{
			firs[0]++;
		}
		else
		{
			seco[0]++;
		}
	}
	if(s[2][0] == s[1][1] && s[1][1] == s[0][2])
	{
		if(s[2][0] == 'X')
		{
			firs[0]++;
		}
		else
		{
			seco[0]++;
		}
	}
	for(int i = 0; i < 3; i++)
	{
		if((s[i][0] == s[i][1] && s[i][1] == s[i][2]))
		{
			if(s[i][i] == 'X')
			{
				firs[1]++;
			}
			else
			{
				seco[1]++;
			}
		}
		if( (s[0][i] == s[1][i] && s[1][i] == s[2][i]))
		{
			if(s[i][i] == 'X')
			{
				firs[2]++;
			}
			else
			{
				seco[2]++;
			}
		}
	}
	fir = firs[0] + firs[1] + firs[2];
	sec = seco[0] + seco[1] + seco[2];
	cerr << fir  << "  " << sec << endl;
	if((fir > 0 && sec > 0) || (fir > 3) || (sec > 3))
	{
		cout << "illegal" << endl;
		return 0;
	}
	for(int i = 1; i < 3; i++)
	{
		if(firs[i] == 2 || seco[i] == 2)
		{
			cout << "illegal" << endl;
			return 0;
		}
	}
	if(fir != 0)
	{
		cout << "the first player won" << endl;
		return 0;
	}
	if(sec != 0)
	{
		cout << "the second player won" << endl;
		return 0;
	}



	if(x + o == 9)
	{
		cout << "draw" << endl;
		return 0;
	}
	else
	{
		if(x == 0)
		{
			cout << "first" << endl;
			return 0;
		}
		else
		{
			cout << "second" << endl;
		}
	}

}