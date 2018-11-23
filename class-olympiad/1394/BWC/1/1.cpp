#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>


using namespace std;
int n;


int main()
{
	cin >> n;
	if(n == 1 || n == 2 || n == 3)
	{
		cout << -1 << endl;
		return 0;
	}
	else
	{
		if(n % 2 == 0)
		{
			for(int i = 0; i < n; i++)
			{
				if(i + n - 1 == n)
					printf("%d ", n);				
				else
					printf("%d ", ((i + n - 1) % n));
			}
		}
		else
		{
			for(int i = 0; i < n; i++)
			{
				if(i + n - 1 == n)
					printf("%d ", n);
				else if(i + n - 2 == n)
					printf("%d ", n - 1);
					else
						printf("%d ", ((i + n - 2) % n));

			}
		}
	}
	cout << endl;
}