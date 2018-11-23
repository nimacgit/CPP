#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>


using namespace std;



int main()
{
	long long n;
	cin >> n;
	int co = 0;
	while(n > 0)
	{
		if(n % 2 == 1)
			co++;
		n /= 2;
	}
	cout << co << endl;
}