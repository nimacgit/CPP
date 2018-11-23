#include <iostream>

using namespace std;

int main()
{
	int maxim = 0;
	int a[20][20];
	for(int i = 0; i < 20; i++)
		for(int j = 0; j < 20; j++)
			cin >> a[i][j];
	for(int i = 0; i < 20; i++)
	{
		for(int j = 0; j < 17; j++)
		{
			int templ = 1;
			for(int k = 0; k < 4; k++)
				templ *= a[i][j + k];
			maxim = max(templ, maxim);
		}
	}
	for(int i = 0; i < 17; i++)
	{
		for(int j = 0; j < 20; j++)
		{
			int templ = 1;
			for(int k = 0; k < 4; k++)
				templ *= a[i + k][j];
			maxim = max(templ, maxim);
		}
	}
	for(int i = 0; i < 17; i++)
	{
		for(int j = 3; j < 20; j++)
		{
			int templ = 1;
			for(int k = 0; k < 4; k++)
				templ *= a[i + k][j - k];
			maxim = max(templ, maxim);
		}
	}
	for(int i = 0; i < 17; i++)
	{
		for(int j = 0; j < 17; j++)
		{
			int templ = 1;
			for(int k = 0; k < 4; k++)
				templ *= a[i + k][j + k];
			maxim = max(templ, maxim);
		}
	}
	cout << maxim << endl;

}