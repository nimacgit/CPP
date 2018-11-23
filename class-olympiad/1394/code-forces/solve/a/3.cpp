#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	int x,y, x2, y2;
	cin >> s;
	x = s[0] - 'a';
	y = s[1] - '0';
	cin >> s;
	x2 = s[0] - 'a';
	y2 = s[1] - '0';
	int counter = 0;
	s.clear();
	while(x != x2 || y != y2)
	{
		counter++;
		if(y2 > y)
		{
			if(x2 > x)
			{
				s += "RU ";
				x++;
				y++;
			}
			else
			{
				if(x2 == x)
				{
					s += "U ";
					y++;
				}
				else
				{
					s += " LU ";
					y++;x--;
				}
			}
		}
		else
		{
			if(y2 == y)
			{
				if(x2 > x)
				{
					s += "R ";
					x++;
				}
				else
				{
					s += " L ";
					x--;
				}
			}
			else
			{
				if(x2 > x)
				{
					s += "RD ";
					x++;
					y--;
				}
				else
				{
					if(x2 == x)
					{
						s += "D ";
						y--;
					}
					else
					{
						s += " LD ";
						y--;x--;
					}
				}	
			}
		}
	}
	cout << counter << endl;
	for(int i = 0; i < s.length(); i++)
	{
		while(s[i] != ' ')
		{
			cout << s[i];
			i++;
		}
		cout << endl;
	}

}