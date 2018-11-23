#include <iostream>
#include <string>

using namespace std;

string s;

int main()
{
	int n;
	cin >> n;
	while(n)
	{
		n--;
		cin >> s;
		int maxs = s.length();
		{
			if(s[maxs - 1] == 'f')
			{
				s[maxs - 1] = 'v';
				s += 'e';
				s += 's';
			}
			else
			{
				if((s[maxs - 1] == 'e' && s[maxs - 2] == 'f'))
				{
					s[maxs - 1] = 'e';
					s[maxs - 2] = 'v';
						s += 's';
				}
				else
				{
					if(s[maxs - 1] == 'x' || s[maxs - 1] == 'o' || s[maxs - 1] == 's' )
					{
						s += 'e';
						s += 's';
					}
					else
					{
						if(s[maxs - 1] == 'h' && s[maxs - 2] == 'c')
						{
							s += 'e';
							s += 's';
						}
						else
						{
							if(s[maxs - 1] == 'y')
							{
								s[maxs - 1] = 'i';
								s += 'e';
								s += 's';
							}
							else
							{
								s += 's';
							}
						}
					}
				}
			}
		}
		cout << s << endl;
	}
	
}