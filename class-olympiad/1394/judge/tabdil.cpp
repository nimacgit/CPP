#include <iostream>
#include <string>

using namespace std;

const int maxn = 5000 + 2;
int d[2][maxn];
int parent[maxn][maxn];
int del, rep, add;
int n,m;
string a,b;

void findcost()
{
	for(int j = 1; j <= m; j++)
	{
		d[0][j] = d[0][j - 1] + del;
		parent[0][j] = 1;
	}
	for(int i = 1; i <= n; i++)
		parent[i][0] = 3;
	for(int i = 1; i <= n; i++)
	{
		d[i % 2][0] = d[(i - 1) % 2][0] + add;
		for(int j = 1; j <= m; j++)
		{
			d[i % 2][j] =  min(d[(i - 1) % 2][j] + add, d[i % 2][j - 1] + del);
			if(a[i - 1] == b[j - 1])
				d[i % 2][j] = min(d[i % 2][j], d[(i - 1) % 2][j - 1]);
			else
				d[i % 2][j] = min(d[i % 2][j], d[(i - 1) % 2][j - 1] + rep);
			if(d[i % 2][j] == d[(i - 1) % 2][j] + add)
				parent[i][j] = 3;
			else 
			{
				if(d[i % 2][j] == d[i % 2][j - 1] + del)
					parent[i][j] = 1;
				else 
				{
					if(d[i % 2][j] == d[(i - 1) % 2][j - 1] + rep)
						parent[i][j] = 2;
					else
						parent[i][j] = 4;
				}
			}
		}
		/*
		for(int j = 0; j <= m; j++)
			cout << d[0][j] << " ";
		cout << endl;
		for(int j = 0; j <= m; j++)
			cout << d[1][j] << " ";
		cout << endl << endl;
		*/
	}
}

void print(int i, int j)
{
	if(parent[i][j] != 0)
	{
		if(parent[i][j] == 3)
		{
			cout << "Insert " << j << " " << a[i - 1] << endl;
			print(i - 1, j);
		}
		else
		{
			if(parent[i][j] == 2)
			{
				cout << "Replace " << j << " " << a[i - 1] << endl;
				print(i - 1, j - 1);
			}
			else
			{
				if(parent[i][j] == 1)
				{
					cout << "Delete " << j  << endl;
					print(i, j - 1);
				}
				else
				{
					print(i - 1, j - 1);
				}
			}
		}
	}
}

int main()
{
	cin >> del >> rep >> add;
	cin >> a >> b;
	n = a.length();
	m = b.length();
	findcost();
	/*
	for(int i = 0; i <= 1; i++)
	{
		for(int j = 0; j <= m; j++)
			cout << d[i][j] << " ";
		cout << endl;
	}
	*/
	cout << d[n % 2][m] << endl;
	print(n,m);

}