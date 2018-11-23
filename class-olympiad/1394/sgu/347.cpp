#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdio.h>



using namespace std;


vector <string> vec;
int n;
string s;

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> s;
		vec.push_back(s);
	}
	sort(vec.begin(), vec.end());
	for(int i = 0; i < n - 1; i++)
		if(vec[i] + vec[i + 1] > vec[i] + vec[i + 1])
			swap(vec[i], vec[i + 1]);
	for(int i = 0; i < n; i++)
		cout << vec[i];
	cout << endl;
	
}