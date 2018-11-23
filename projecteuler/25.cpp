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
string sum(string s,string si)
{
	long long int a,b=0;
	int ma=max(s.length(),si.length());
	string so;
	so.resize(ma);
	int f=0;
	s=rev(s);
	si=rev(si);
	for(int i=0;i<so.length() || b!=0 ;i++)
	{
        if(i<s.length())
        {
            a=int(s[i]-48);
        }
        else
            f=1;
		if(i<si.length())
		{
            if(f==1)
            {
                a=int(si[i]-48);
                f=0;
            }
            else
                a+=int(si[i]-48);
		}
		a+=b;
		so[i]=char(a%10+48);
		b=a/10;
		if(i== so.length()-1 && b!=0)
		{
            so+='0';
            si+='0';
            s+='0';
		}
	}

	return(rev(so));
}

int main()
{
    string a="1",b="1",c;
    int ma=2;
    for(int i=1;i!=1000;i=b.length())
    {
        c=sum(a,b);
        a=b;
        b=c;
        ma++;
    }
    cout<<b<<endl<<ma<<endl;

    return 0;
}
