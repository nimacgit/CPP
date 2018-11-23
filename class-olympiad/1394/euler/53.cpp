#include <iostream>

using namespace std;

int d[102][102];


int main()
{
	d[1][1] = 1;
	d[1][0] = 1;
	d[0][1] = 0;
	d[0][0] = 1;
	for(int i = 1; i <= 101; i++)
		d[0][i] = 0;
	for(int i = 1; i <= 101; i++)
		d[i][0] = 1;
	int sum = 0;
	for(int i = 1; i <= 100; i++)
	{
		for(int j = 1; j <= 100; j++)
		{
			if(d[i - 1][j] >= 1000000 || d[i - 1][j - 1] >= 1000000)
				d[i][j] = 1000002;
			else
				d[i][j] = d[i - 1][j] + d[i - 1][j - 1];
			if(d[i][j] > 1000 * 1000 )
			{
				//cout << d[i][j] << endl;
				sum++;
			}
		}
	}

	cout << sum << endl;
	
}