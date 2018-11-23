#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

string y="yes", n = "no", co = "composite", p = "prime";
int primes[15] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
string ans;
bool ask(int i)
{
	while(i < 15)
	{
		cout << primes[i] << endl;
		cin >> ans;
		if(ans == y)
			return true;
		i++;
	}
	return false;
}

int main()
{

	cout << 2 << endl;
	cin >> ans;
	if(ans == y)
	{
		cout << 4 << endl;
		cin >> ans;
		if(ans == y)
			cout << co << endl;
		else
		{
			if(ask(1))
				cout << co << endl;
			else
				cout << p << endl;
		}
	}
	else
	{
		cout << 3 << endl;
		cin >> ans;
		if(ans == y)
		{
			cout << 9 << endl;
			cin >> ans;
			if(ans == y)
			{
				cout << co << endl;
			}
			else
			{
				if(ask(2))
					cout << co << endl;
				else
					cout << p << endl;
			} 
		}
		else
		{
			cout << 5 << endl;
			cin >> ans;
			if(ans == y)
			{
				cout << 25 << endl;
				cin >> ans;
				if(ans == y)
				{
					cout << co << endl;
				}
				else
				{
					if(ask(3))
						cout << co << endl;
					else
						cout << p << endl;
				} 
			}
			else
			{
				cout << 7 << endl;
				cin >> ans;
				if(ans == y)
				{
					cout << 49 << endl;
					cin >> ans;
					if(ans == y)
					{
						cout << co << endl;
					}
					else
					{
						if(ask(4))
							cout << co << endl;
						else
							cout << p << endl;
					} 

				}
				else
					cout << p << endl;
			}
		}
	}
	fflush(stdout);

}
