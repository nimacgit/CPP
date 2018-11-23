#include <iostream>
#include <string>

using namespace std;

int main()
{
	int mj = 22;
	int mi = 13;
	int a[mi][mj];
	int b[mi][mj];

	for(int i = 0;i < mi ; i++)
	{
		for(int j = 0; j < mj ; j++)
			b[i][j] = a[i][j]=0;
	}	
	for(int i = 1;i < mi -1; i++)
	{
		string s;
		cin>>s;
		for(int j =1; j < mj -1; j++)
		{
			a[i][j] = int(s[j-1]) - 48;
			b[i][j] = a[i][j];
		}
	}
	for(int i = 1;i < mi -1; i++)
	{
		for(int j = 1; j < mj -1; j++)
		{
			if(b[i - 1][j] == 1 || b[i+1][j]==1 || b[i+1][j+1]==1 || b[i+1][j-1]==1 || b[i-1][j+1]==1 || b[i-1][j-1]==1 || b[i][j+1]==1 || b[i][j-1]==1)
			{
				a[i][j] = 1;
			}
		}
	}
	for(int i = 1;i < mi -1; i++)
	{
		for(int j = 1; j < mj-1; j++)
			b[i][j] = a[i][j];
	}	
	for(int i = 1;i < mi-1; i++)
	{
		for(int j =1; j < mj-1; j++)
		{
			if(a[i][j+1] == 1 && a[i+1][j] == 1 && a[i - 1][j] == 1 && a[i][j-1] == 1)
				b[i][j]=0;
		}
	}
	for(int i = 1;i < mi - 1; i++)
	{
		for(int j = 1; j < mj - 1; j++)
			cout<<b[i][j];
		cout << endl;
	}			
}