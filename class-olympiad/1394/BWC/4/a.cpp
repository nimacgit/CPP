#include <bits/stdc++.h>


using namespace std;

int maxn = 100;
int delta  = 648481;
int co = 0;
/*double abs(double a)
{
	if(a < 0)
		return (double)-1.000 * a;
	return a;
}
*/

int main()
{
	for(int i = 0; i < maxn; i++)
	{
		for(int j = 0; j < maxn; j++)
		{
			for(int i1 = 0; i1 < maxn; i1++)
			{
				for(int j1 = 0; j1 < maxn; j1++)
				{
					if(i != i1 && j1 != j && (abs(((double)(j - j1) / (double)(i - i1))) != 1))
					{
						if(abs(i - i1) != 2 || abs(j - j1) != 1)
						{
							if(abs(i - i1) != 1 || abs(j - j1) != 2)
							{
								co = (co + 1) % delta;
							}
						}
					}
				}
			}			
		}
	}
	cout << co  << endl;
}
