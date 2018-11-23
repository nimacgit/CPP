#include <iostream>

using namespace std;

const int maxn = 1000 * 1000;

bool notprime[maxn + 10];

void findprime()
{
	notprime[1] = true;
	for(int i = 2; i < maxn; i++)
	{
		if(!notprime[i])
		{
			for (int j = 2; j * i < maxn; j++)
				notprime[i * j] = true;
		}
	}
}

int find(int a, int b)
{
	for(int i = 0; i < 10000; i++)
	{
		if(i * i + a * i + b > 0)
		{
			if(notprime[i * i + a * i + b])
				return i;
		}
		else
			return i;
	}
}

int main()
{
	findprime();
	int sum, maxim = 0;
	for(int a = -1000; a < 1000; a++)
	{
		for(int b = -1000; b < 1000; b++)
		{
			//cout << a << " " << b << endl;
			int temp = find(a, b);
			if(temp > maxim)
			{
				maxim = temp;
				sum = a * b;
			}
		}
	}
	cout << sum << endl;

}