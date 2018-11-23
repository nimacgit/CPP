#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>


using namespace std;

int s, q, t, co = 1;

int main()
{
	cin >> t >> s >> q;
	while(s * q < t)
	{
		co++;
		s = s * q;
	}
	cout << co << endl;
}