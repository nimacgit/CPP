#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>


using namespace std;

vector <string> myvec;
string s;
int k;

int main()
{
	cin >> s >> k;
	for(int i = 1; i <= s.length(); i++)
		for(int j = 0; j + i <= s.length(); j++)
			myvec.push_back(s.substr(j, i));
	sort(myvec.begin(), myvec.end());
	cout << myvec[k - 1] << endl;
}