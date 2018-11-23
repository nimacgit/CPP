#include <iostream>
#include <string>

using namespace std;

long long int t=0;
long long int p=0;
long long int h=0;
long long int ip=1;
long long int it=1;
long long int ih=1;

void tm(long long  int n)
{
	t=(n*(n+1))/2;
}

void pm (long long  int n)
{
	p=(n*((3*n)-1))/2;
}
void hm (long long  int n)
{
	h=(n*((2*n)-1));
}

int f=0;

int main()
{
	for(;f!=2;)
	{
		if(p<t)
		{
			if(p<h)
			{
				ip++;
				pm(ip);
			}
			else
			{
				ih++;
				hm(ih);
			}
		}
		else
		{
			if(t<h)
			{
				it++;
				tm(it);
			}
			else
			{
				ih++;
				hm(ih);
			}

		}
		if(h==p && h==t && t==p)
		{
			f++;
			cout<<t<<endl;
		}
	}
}
