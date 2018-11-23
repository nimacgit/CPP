#include <iostream>
#include <string>
#include <stdio.h>
#include <ctype.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int a[s.length()];
	for(int i = 0; i < s.length(); i++)
		a[i] = 1;
	int foundf = s.find("<UP>");
	int foundl = s.find("</UP>",foundf);
	int foundfd = s.find("<DOWN>");
	int foundld = s.find("</DOWN>", foundfd);
	while(foundf != -1)
	{
		a[foundf] = 0;
		a[foundf + 1] = 0;
		a[foundf + 2] = 0;
		a[foundf + 3] = 0;
		foundf = s.find("<UP>",foundf + 1);
	}
	while(foundl != -1)
	{
		a[foundl] = -1;
		a[foundl + 1] = -1;
		a[foundl + 2] = -1;
		a[foundl + 3] = -1;
		a[foundl + 4] = -1;
		foundl = s.find("</UP>",foundl + 1);
	}
	while(foundfd != -1)
	{
		a[foundfd] = -2;
		a[foundfd + 1] = -2;
		a[foundfd + 2] = -2;
		a[foundfd + 3] = -2;
		a[foundfd + 4] = -2;
		a[foundfd + 5] = -2;
		foundfd = s.find("<DOWN>",foundfd + 1);
	}
	while(foundld != -1)
	{
		a[foundld] = -3;
		a[foundld + 1] = -3;
		a[foundld + 2] = -3;
		a[foundld + 3] = -3;
		a[foundld + 4] = -3;
		a[foundld + 5] = -3;
		a[foundld + 6] = -3;
		foundld = s.find("</DOWN>",foundld + 1);
	}
//	for(int i = 0; i < s.length(); i++)
//		cout << a[i] << " ";
//	cout << endl;
	for(int i = 0; i < s.length(); i++)
	{
		if(a[i] == 1)
		{
			bool flag = 0;
			int counter = 0;
			int counterd = 0;
			for(int j = i - 1; j >= 0 && !flag; j--)
			{
				if(s[j] == '>')
				{
					if(a[j] == -3)
						counterd ++;
					else
						if(a[j] == -1)
							counter ++;
						else
							if(j >= 5)
							{
								if(a[j] == -2)
								{
									if(counterd == 0)
									{
										flag = 1;
										s[i] = tolower(s[i]);
									}
									else
										counterd--;
								}
							}
							if(j >= 3)
							{
								if(a[j] == 0)
								{
									if(counter == 0)
									{
										flag = 1;
										s[i] = toupper(s[i]);
									}
									else
										counter--;
								}
							}
				}
			}
		}
	}
	int count = 0;
	for(int i = 0; i - count < s.length(); i++)
		if(a[i] < 1)
		{
			s.erase(s.begin() + i - count);
			count++;
		}
	cout << s << endl;
}