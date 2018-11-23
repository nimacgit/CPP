#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <algorithm>


using namespace std;

string s;
vector <string> v;
int find(string l)
{
	int sum = 0;
	for(int i = 0; i < l.length(); i++)
		sum += l[i] - 'A' + 1;

	return sum;
}


int main()
{
	s = "10";
	while(s != "2")
	{
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(), v.end());
	cout << v.size() << endl;
	cout << v[1] << "  " << v[938] << "  " << v[3] << endl;
	cout << find(v[938]) << endl;
	long long sum = 0;
	for(int i = 1; i < v.size(); i++)
		sum += (i * find(v[i]));
	cout << sum << endl;
}