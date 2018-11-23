#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <set>

using namespace std;


const int delta = 648481;
set <int> myset;

int main()
{
	for(long long i = 0; i < delta / 1000; i++)
		myset.insert((i * i * i) % delta);
	while(!myset.empty())
	{
		cout << *myset.begin() << endl;
		myset.erase(myset.begin());
	}
}