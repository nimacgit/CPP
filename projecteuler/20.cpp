#include <iostream>
#include <string>

using namespace std;

string rev(string a)
{
	string b=a;
	for(int i=0;i<a.length();i++)
	{
		b[a.length()-i-1]=a[i];
	}
	return b;
}
string mult(string s,int in)
{
	long long int a,b=0;
	s=rev(s);
	for(int i=0;i<s.length() || b!=0;i++)
	{
		a= ((s[i])-48)*in + b;
		s[i]=char(a%10+48);
		b=a/10;
		if(b!=0 && i==s.length()-1)
		{
            s=s+'0';
		}

	}

	return(rev(s));
}
int main()
{
	string a="1";
	for(int i=1;i<=100;i++)
	{
		a=mult(a,i);
	}
	long long int sum=0;
	for(int i=0;i<a.length();i++)
	{
        sum+=int(a[i]-48);
	}
	cout<<sum;


}



