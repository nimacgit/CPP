#include <iostream>

using namespace std;

int main()
{
	int n, sum = 0;
	cin >> n;
	if(n % 1000 != 0)
	{
		cout << "SORRY" << endl;
		return 0;
	}
	else
	{
		n /= 1000;
		if(n >= 1)
		{
			n -= 1;
			sum++;
		}
		if(n >= 2)
		{
			n -= 2;
			sum++;
		}
		if(n >= 5)
		{
			n -= 5;
			sum++;
		}
		if(n >= 10)
		{
			n -= 10;
			sum++;
		}
		while(n >= 10)
		{
			n -= 10;
			sum++;
		}
		while(n >= 5)
		{
			n -= 5;
			sum++;
		}
		while(n >= 2)
		{
			n -= 2;
			sum++;
		}
		while(n >= 1)
		{
			n -= 1;
			sum++;
		}
	}
	cout << sum << endl;
		
	
}