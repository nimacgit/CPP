#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

string s;
int way=1;


int main()
{
	cin>>s;
	for(int i=0;;i+=way)
	{
		if(i==-1)
		{
			printf("YES\n");
			return 0;
		}
 		if(i==s.length())
		{
			printf("NO\n");
			return 0;
		}
		if(s[i]=='X')
		{
			way*=-1;
			s[i]='O';
		}
		else
		{
			s[i]='X';
		}
	}

}
