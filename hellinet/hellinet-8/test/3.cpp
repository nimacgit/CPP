#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

string s;

int main()
{
	cin>>s;
	int n=0;
	for(int i=0;i<s.length();i++)
		if(s[i]=='L')
			n++;
	n=n/2;
	if(s.length()+1-n>s.length())
		cout<<s.length()<<endl;
	else
		cout<<s.length()+1-n<<endl;

}
