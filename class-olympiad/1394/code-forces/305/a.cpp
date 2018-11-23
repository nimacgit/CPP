#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <algorithm>



using namespace std;


string t, s;

bool pal()
{
	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] != s[s.length() - i - 1])
			return false;
	}
	return true;
}

int main()
{
	int n, k;
	cin >> t;
	cin >> k;
	n = t.length();
	if(double(n / (double) k) != int(n / k))
	{
		cout << "NO" << endl;
		return 0;
	}
	for(int i = 0; i < t.length(); i += n / k)
	{
		s = t.substr(i,(n / k));
		if(!pal())
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;


}