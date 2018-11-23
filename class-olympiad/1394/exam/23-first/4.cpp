#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <set>

using namespace std;


set <string> numset;
int a[4];
int b[4];
string s;

void makenum()
{
	s.clear();
	for(int i = 0; i < 4; i++)
		s += a[i];
	for(int i = 0; i < 4; i++)
		s += b[i];
	numset.insert(s);
}


void check(int i, int j)
{
	//cerr << i << "  " << j << endl;
	if(i == 3 && j == 4)
		makenum();
	else
	{
		if(j == 4)
		{
			j = 0;
			i++;
		}
		check(i, j + 1);
		a[i]++;
		b[j]++;
		check(i, j + 1);
		a[i]--;
		b[j]--;
	}

}

int main()
{
	check(0, 0);
	cout << numset.size() << endl;
}