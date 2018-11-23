#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 1389;
const int delta = 90907;
string s;
string num;

void numplus()
{
	reverse(num.begin(), num.end());
	num[0]++;
	for(int i = 0; num[i] == '2'; i++)
	{
		num[i] = 48;
		if(i == num.length() - 1)
			num+='1';
		else
			num[i + 1]++;
	}
	reverse(num.begin(), num.end());
}


bool isok(int i)
{
	int k = 0;
	while(i < s.length())
	{
		if(num[k] != s[i])
		{
			return false;
		}
		k++;
		i++;
	}
	return true;
}

void adds(int a)
{
	for(int i = s.length() - a; i < num.length(); i++)
		s += num[i];
}

int main()
{
	num = "1";
	s = "1";
	for(int i = 2; i <= maxn; i++)
	{
		numplus();
		//cout << s << "  " << num << endl;
		int j;
		for(j = s.length() - num.length(); j < s.length() || j < 0; j++)
		{
			if(j < 0)
				j = 0;
			if(isok(j))
			{
				adds(j);
				j = s.length();
			}
		}
		if(j == s.length())
			adds(s.length());
	}
	cout << (s.length() * maxn) % delta << endl;
}