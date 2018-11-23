#include <iostream>

using namespace std;

long long isok(long long a)
{
	a *= a;
	a /= 10000;
	int i = 8;
	while(a != 0)
	{
		if(a % 10 == i)
		{
			a /= 100;
			i--;
		}
		else
			return false;
	}
}

int x[24]=
{
	430,
530,
830,
1670,
1970,
2070,
2930,
3030,
3330,
4170,
4470,
4570,
5430,
5530,
5830,
6670,
6970,
7070,
7930,
8030,
8330,
9170,
9470,
9570

};

const long long maxn = 1389026623;

int main()
{
	for(long long i = 10000; i < maxn ; i+= 10000)
	{
		for(int j = 0; j <= 23; j++)
		{
			i += x[j];
			if(isok(i))
				cout << i << endl;
			i -= x[j];
		}

	}
}