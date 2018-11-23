#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair

using namespace std;

typedef pair<int, int> pie;

int n;
string s;
vector<int> open;
int co = 0;

int main()
{

	cin >> s;
	for(int i = 0; i < s.length(); i++)
	{
		switch (s[i])
		{
			case '(':
				open.push_back(0);
				break;
			case '[':
				open.push_back(1);
				break;
			case '<':
				open.push_back(2);
				break;
			case '{':
				open.push_back(3);
				break;
			case ')':
				if(open.empty())
				{
					cout << "Impossible" << endl;
					return 0;
				}
				if(open.back() != 0)
					co++;
				open.pop_back();
				break;
			case ']':
				if(open.empty())
				{
					cout << "Impossible" << endl;
					return 0;
				}
				if(open.back() != 1)
					co++;
				open.pop_back();
				break;
			case '>':
				if(open.empty())
				{
					cout << "Impossible" << endl;
					return 0;
				}
				if(open.back() != 2)
					co++;
				open.pop_back();
				break;
			case '}':
				if(open.empty())
				{
					cout << "Impossible" << endl;
					return 0;
				}
				if(open.back() != 3)
					co++;
				open.pop_back();
				break;

		}
	}
	if(open.empty())
		cout << co << endl;
	else
		cout << "Impossible" << endl;
}

