#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

string s;
long long k2;
long long k;
long long amal = 0;
long long pos = 0;

void findmax()
{
	for(int i = 0; i  < s.length() + amal; i++)
	{
		while( i > 0 && s[i - amal] > s[i - 1 - amal] && k2 > 0 && i > pos + amal)
		{
			//cout << "s[i] = " << s[i - amal] << " s[ j ] = " << s[i - 1 - amal] << "pos = " << pos << " i = " << i << "  " <<  amal << endl;
			s.erase(s.begin() + i - 1 - amal);
			k2--;
			amal++;
		}
		if(i >= k)
			pos++;
	}
	while(k2)
	{
		s.erase(s.begin() + s.length() - 1);
		k2--;
	}
}

int main()
{
	cin >> s >> k;
	k2 = k;
	findmax();
	cout << s << endl;

}