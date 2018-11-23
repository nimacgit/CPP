#include <iostream>
#include <math.h>
#include <string>
#include <stdlib.h>
using namespace std;

double a[1000];
string s;

int find()
{
	for(int j = 0; j < s.length(); j++)
		if(s[j] == ',')
			return j;
}

int main()
{
	for(int i = 0; i < 1000; i++)
	{
		cin >> s;
		int k = find();
		cout << s << " " << k << endl;
		int num1 = atoi(s.substr(0, k).c_str());
		int num2 = atoi(s.substr(k + 1, s.length() - k - 1).c_str());
		a[i] = log2(num1) * num2;
	}
	int maxi = 0;
	for(int i = 0; i < 1000; i++)
	{
		if(a[i] > a[maxi])
			maxi = i;
	}
	cout << maxi + 1 << endl;

}