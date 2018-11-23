#include <iostream>

using namespace std;

bool isprime(int a)
{
	for (int i = 2; i * i <= a; i++)
	{
		if(a % i == 0)
			return false;
	}
	return true;
}

int main()
{
	int n,a;
	cin >> n;
	bool flag = false;
	while(n)
	{
		n--;
		cin >> a;
		flag = false;
		for(int i = 2, temp = a; i * i <= a; i++)
		{
			if(a % i == 0)
			{
				if(isprime(a/i))
					cout << "Yes" << endl;
				else
					cout << "No" << endl;
				flag = true;
				i = a;
			}
		}
		if(!flag)
			cout << "No" << endl;
	}
	
}