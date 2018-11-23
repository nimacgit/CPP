#include <iostream>

using namespace std;

const int maxn = 1389;
const int delta = 90907;
bool a[maxn];

bool isprime(int a)
{
	for(int i = 2; i * i <= a; i++)
		if(a % i == 0)
			return false;
	return true;
}

int main()
{
	a[0] = false;
	for(int i = 1; i < maxn - 1; i++)
	{
		if(isprime(i + 1))
			a[i] = true;
		else
			a[i] = false;
	}
	bool change = true;
	int s = 0;
	while(change)
	{
		change = false;
		for(int i = 0; i < maxn - 1; i++)
			if(a[i] == true && a[i + 1] == false)
			{
				change = true;
				a[i] = false;
				a[i + 1] = true;
				i++;
			}
		if(change)
			s++;
	}
	cout << (s + s * s + ((s * s) % delta) * s) % delta << endl;
}