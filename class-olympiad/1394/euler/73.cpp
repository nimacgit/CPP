#include <iostream>

using namespace std;

bool mark[12001][12001];


bool isfirst(int a, int b)
{
	int minimum = min(a, b);
	for(int i = 2; i <= minimum; i++)
	{
		if(a % i == 0 && b % i == 0)
			return false;
	}
	return true;
}



int main()
{
	long long sum = 0;
	for(int d = 2; d <= 12000; d++)
	{
		//cout << i << endl;
		for(int n = 1; n < d; n++)
		{
			if(!mark[n][d])
			{
				if(3 * n > d && 2 * n < d)
				{

					//cout << n << " " <<  d << endl;
					if(isfirst(n, d))
					{
							sum++;
					}
					else
					{
						mark[n][d] = true;
						for(int k = 2; k * n < d; k++)
							mark[k * n][d] = true;
						for(int k = 2; k * d <= 12000; k++)
							mark[n][k * d] = true;
					}
				}
			}
		}
	}
	cout << sum << endl;

}