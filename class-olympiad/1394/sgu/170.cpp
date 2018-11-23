#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdio.h>



using namespace std;

string a, b;
vector <int> onea, oneb;
int sum = 0;

int abs(int a)
{
	if(a < 0)
		return -1 * a;
	return a;
}

int main()
{
	cin >> a >> b;
	if(a.length() != b.length())
	{
		cout << -1 << endl;
		return 0;
	}
	for(int i = 0; i < a.length(); i++)
	{
		if(a[i] == '+')
			onea.push_back(i);
		if(b[i] == '+')
			oneb.push_back(i);
	}
	if(onea.size() != oneb.size())
	{
		cout << -1 << endl;
		return 0;
	}
	for(int i = 0; i < onea.size(); i++)
		sum += abs(onea[i] - oneb[i]);
	cout << sum << endl;
}