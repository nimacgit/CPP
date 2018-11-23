#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	n = n % 3;
	if(n == 0)
		cout << "HabbeyeAngoor" << endl;
	else
		if(n == 1)
			cout << "Shangool" << endl;
		else 
			cout << "Mangool" << endl;

}