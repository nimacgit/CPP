#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <map>
using namespace std;

string s;
vector <string> words;
const int maxpair = 1743;
vector <string> anagram[1743];
map <string, int> squers[10];
vector <int> number[10];


bool issame(string a, string b)
{
	int as[33], bs[33];
	for(int i = 0; i < 33; i++)
		as[i] = bs[i] = 0;
	for(int i = 0; i < a.length(); i++)
		as[a[i] - 'A']++;
	for(int i = 0; i < b.length(); i++)
		bs[b[i] - 'A']++;
	for(int i = 0; i < 33; i++)
		if(as[i] != bs[i])
			return false;
	return true;
}


int main()
{
	s = "2";
	while(s != "-2")
	{
		cin >> s;
		if(s != "-2")
			words.push_back(s);
	}
	
	for(int i = 0; i < words.size(); i++)
	{
		for(int j = i + 1; j < words.size(); j++)
			if(issame(words[i], words[j]))
			{
				anagram[i].push_back(words[j]);
				words.erase(words.begin() + j);
				j--;
			}
	}
	for(int i = 0; i < maxpair; i++)
	{
		cout << anagram[i][0] << endl;
		cout << anagram[i][0].length() << endl;
		number[anagram[i][0].length()].push_back(i);
	}
	for(int i = 1; i < 10; i++)
	{

	}

}