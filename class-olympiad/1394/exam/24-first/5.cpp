#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <set>

using namespace std;


int co = 0;
int a[7];
int b[7];


void check(int i, int j)
{
	cout << i << "   " << j << "  " << a[i] << "  " << b[j] << endl;
	//cerr << i << "  " << j << endl;
	if(i == 6 && j == 7)
		co++;
	else
	{
		if(j == 7)
		{
			i++;
			j = 0;
		}
		if((j == 5 || j == 6) && (i == 5 || i == 6))
		{
			if(j == 5 && i == 6)
			{
				if(b[j] < 2)
					return;
				else if(b[j] == 2 && a[i] < 3)
				{
					b[j]++;
					a[i]++;
					check(i, j + 1);
					b[j]--;
					a[i]--;
				}
				else if(b[j] == 3)
				{
					check(i, j + 1);
				}

			}
			else if(i == 6 && j == 6)
			{
				if((a[i] == 3 && b[i] == 3) || (a[i] == 2 && b[i] == 2))
					check(i, j + 1);
			}
			else if(i = 5 && j == 5)
			{
				if(a[i] < 1 || b[i] < 1)
					return;
				else
				{
					if(a[i] == 1)
					{
						if(b[j] == 2 || b[j] == 1)
						{
							a[i]++;
							b[j]++;
							check(i, j + 1);
							a[i]--;
							b[j]--;
						}
						else
							return;
					}
					else if(a[i] == 2)
					{
						if(b[j] == 1 || b[j] == 2)
						{
							a[i]++;
							b[j]++;
							check(i, j + 1);
							a[i]--;
							b[j]--;
							if(b[j] == 2)
								check(i, j + 1);
						}
						else
							return;
					}
					else
						check(i, j + 1);
				}
			}
			else
			{
				if(a[i] < 2)
					return;
				else if(a[i] == 2 && b[j] < 3)
				{
					b[j]++;
					a[i]++;
					check(i, j + 1);
					b[j]--;
					a[i]--;
				}
				else if(a[i] == 3)
				{
					check(i, j + 1);
				}
			}

		}
		else if(i == 5 || i == 6)
		{
			if(i == 5)
			{
				if(b[j] == 0)
					return;
				else if(b[j] == 1 && a[i] < 3)
				{
					a[i]++;
					b[j]++;
					check(i, j + 1);
					a[i]--;
					b[j]--;
				}
				else if(b[j] == 2)
				{

					check(i, j + 1);
					if(a[i] < 3)
					{
						a[i]++;
						b[j]++;
						check(i, j + 1);
						a[i]--;
						b[j]--;
					}
				}
				else if(b[j] == 3)
				{
					check(i, j + 1);
				}
			}
			if(i == 6)
			{
				if(b[j] < 2)
					return;
				else if(b[j] == 2 && a[i] < 3)
				{
					a[i]++;
					b[j]++;
					check(i, j + 1);
					a[i]--;
					b[j]--;
				}
				else if(b[j] == 3)
				{
					check(i, j + 1);
				}
			}
		}
		else if(j == 5 || j == 6)
		{
			if(j == 5)
			{
				if(a[i] == 0)
					return;
				else if(a[i] == 1 && b[j] < 3)
				{
					a[i]++;
					b[j]++;
					check(i, j + 1);
					a[i]--;
					b[j]--;
				}
				else if(a[i] == 2)
				{

					check(i, j + 1);
					if(b[j] < 3)
					{
						a[i]++;
						b[j]++;
						check(i, j + 1);
						a[i]--;
						b[j]--;
					}
				}
				else if(a[i] == 3)
				{
					check(i, j + 1);
				}
			}
			if(j == 6)
			{
				if(a[i] < 2)
					return;
				else if(a[i] == 2 && b[j] < 3)
				{
					a[i]++;
					b[j]++;
					check(i, j + 1);
					a[i]--;
					b[j]--;
				}
				else if(a[i] == 3)
				{
					check(i, j + 1);
				}
			}
		}
		else
		{
			check(i, j + 1);
			if(a[i] < 3 && b[j] < 3)
			{
				a[i]++;
				b[j]++;
				check(i, j + 1);
				a[i]--;
				b[j]--;
			}
		}
	}

}

int main()
{
	check(0, 0);
	cout << co << endl;
}