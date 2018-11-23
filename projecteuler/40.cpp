#include <iostream>
#include <string>
using namespace std;

string s;

void add(int a)
{
	for(int i=0;i<to_string(a).length();i++)
	{
		s+=to_string(a)[i];
	}


}

void make(int n)
{
	for(int i=1;i<=n;i++)
	{
		add(i);
	}

}

int main()
{
	make(1000000);
	long long int n;
	cout<<s[0]<<endl<<s[ 9]<<endl<<s[ 99]<<endl<<s[ 999]<<endl<<s[ 9999]<<endl<<s[ 99999]<<endl<<s[999999]<<endl;
	n=(int(s[ 999999])-48)*(int(s[ 99999])-48)*(int(s[ 9999])-48)*(int(s[ 999])-48)*(int(s[ 99])-48)*(int(s[ 9])-48)*(int(s[0])-48);
	cout<<n<<endl;


}
