#include <iostream>
#include <string>
#include <stdio.h>
#include <ctype.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int foundf = s.find("<UP>");
	int foundl = s.find("</UP>",foundf);
	int foundfd = s.find("<DOWN>");
	int foundld = s.find("</DOWN>", foundfd);
	for(;foundf != -1 || foundfd != -1;)
	{
		if((foundf < foundfd || foundfd == -1) && foundf != -1)
		{
//			cout << "ze" << endl;
			for(int i = foundf + 1; i < foundl; i++)
				s[i] = toupper(s[i]);
			s.erase(s.begin() + foundf);
			s.erase(s.begin() + foundf);
			s.erase(s.begin() + foundf);
			s.erase(s.begin() + foundf);
			s.erase(s.begin() + foundl - 4);
			s.erase(s.begin() + foundl - 4);
			s.erase(s.begin() + foundl - 4);
			s.erase(s.begin() + foundl - 4);
			s.erase(s.begin() + foundl - 4);
		}
		else
		{
//			cout << " ke " << endl;
			for(int i = foundfd + 1; i < foundld; i++)
				s[i] = tolower(s[i]);
			s.erase(s.begin() + foundfd);
			s.erase(s.begin() + foundfd);
			s.erase(s.begin() + foundfd);
			s.erase(s.begin() + foundfd);
			s.erase(s.begin() + foundfd);
			s.erase(s.begin() + foundfd);
			s.erase(s.begin() + foundld - 6);
			s.erase(s.begin() + foundld - 6);
			s.erase(s.begin() + foundld - 6);
			s.erase(s.begin() + foundld - 6);
			s.erase(s.begin() + foundld - 6);
			s.erase(s.begin() + foundld - 6);
			s.erase(s.begin() + foundld - 6);
		}
		foundf = s.find("<up>");
		foundl = s.find("</up>");
		foundfd = s.find("<down>");
		foundld = s.find("</down>");
		while(foundf != -1)
		{
			foundf = s.rfind("<up>");
			if(foundf != -1)
			{
				for(int i = 0; i < 4; i++)
					s[foundf + i] = toupper(s[foundf + i]);
			}
		}
		while(foundl != -1)
		{
			foundl = s.find("</up>");
			if(foundl != -1)
			{
				for(int i = 0; i < 5; i++)
					s[foundl + i] = toupper(s[foundl + i]);
			}
		}
		while(foundfd != -1)
		{
			foundfd = s.find("<down>");
			if(foundfd != -1)
			{
				for(int i = 0; i < 6; i++)
					s[foundfd + i] = toupper(s[foundfd + i]);
			}
		}
		while(foundld != -1)
		{
			foundld = s.find("</down>");
			if(foundld != -1)
			{
				for(int i = 0; i < 7; i++)
					s[foundld + i] = toupper(s[foundld + i]);
			}
		}
		foundf = s.find("<UP>");
		foundl = s.find("</UP>",foundf);
		foundfd = s.find("<DOWN>");
		foundld = s.find("</DOWN>", foundfd);
	}
		
	cout << s << endl;
}