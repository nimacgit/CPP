#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s;


int main()
{
	int n;
	cin >> n;
	cin >> s;
	int a[10];
	for(int i = 1; i <= 9; i++)
		a[i] = 0;
	vector<int> v;
	for(int i = 0, temp; i < n; i++)
	{
		temp = int(s[i])- 48;
		for(int j = 2,tem; j <= temp; j++)
		{
			tem = j;
			while(tem % 2 == 0)
			{
				a[2]++;
				tem /= 2;
			}
			while(tem % 3 == 0)
			{
				a[3]++;
				tem /= 3;
			}
			while(tem % 5 == 0)
			{
				a[5]++;
				tem /= 5;
			}
			while(tem % 7 == 0)
			{
				a[7]++;
				tem /= 7;
			}
		}
	}
	//cout<< " re" << endl;
	for(int i = 7; i >= 1; i--)
		while(a[i] != 0)
		{
			if(i == 7)
			{
				v.push_back(7);
				a[7]--;
				a[5]--;
				a[3]--;
				a[3]--;
				a[2]--;
				a[2]--;
				a[2]--;
				a[2]--;
			}
			if(i == 5)
			{
				v.push_back(5);
				a[5]--;
				a[3]--;
				a[2]--;
				a[2]--;
				a[2]--;
			}
			if(i == 3)
			{
				v.push_back(3);
				a[3]--;
				a[2]--;
			}
			if(i == 2)
			{
				v.push_back(2);
				a[2]--;
			}
		}
		for(int i = 0; i < v.size(); i++)
			cout<< v[i];
		cout << endl;


	}