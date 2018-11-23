#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>


using namespace std;

int d[8][8];

bool check(int x, int y)
{
	if(d[x][y] != d[x - 1][y] && d[x][y] != d[x - 1][y + 1] && d[x][y] != d[x - 1][y - 1] && d[x][y] != d[x][y + 1] && d[x][y] != d[x + 1][y - 1] && d[x][y] != d[x + 1][y] && d[x][y] != d[x + 1][y + 1])
		return true;
	
}


int make(int x, int y)
{
	if(check(x, y))
	{

	}
	else
		return 0;
}

int main()
{

}