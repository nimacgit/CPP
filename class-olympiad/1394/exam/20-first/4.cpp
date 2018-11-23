#include <iostream>

using namespace std;

const int delta = 90907;
bool asleep[61];
int sleep = 0;
int makesleep(int i)
{
	int k = i + 1, j;
	for(j = i; k != 0 ; j = (j + 1) % 60 )
	{
		if(!asleep[j])
			k--;
	}
	int npers = (j - 1 + 60) % 60;
	asleep[npers] = true;
	return npers;
}

void reset()
{
	for(int i = 0; i < 60; i++)
		asleep[i] = false;
	sleep = 0;
}

int findawake()
{
	for(int i = 1; i < 61; i++)
		if(!asleep[i])
			return i;
}
int main()
{
	unsigned long long sum = 1;
	int sperson = 0;
	for(int i = 0; i < 60; i++)
	{
		reset();
		asleep[i] = true;
		sperson = i;
		sleep++;
		for(int j = 1; j < 59; j++)
		{
			//if(i == 1)
				//cerr << sperson << "  " ;
			sperson = makesleep(sperson);
			sleep++;
		}
		int temp = findawake() % 60 + 1;
		sum *= temp;
		cerr << temp << endl;
		sum %= delta;
		//cout << findawake() << endl;
	}
	cout << sum % delta << endl;

}