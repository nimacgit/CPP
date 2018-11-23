#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;
stack <char> st;
string s;

int main()
{
	cin >> s;
	if(s.length() % 2)
	{
		cout << "No" << endl;
		return 0;
	}
	st.push(s[0]);
	for(int i = 1; i < s.length(); i++)
	{

		if(st.empty() || st.top() != s[i])
			st.push(s[i]);
		else
			st.pop();
	}
	if(st.empty())
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}
