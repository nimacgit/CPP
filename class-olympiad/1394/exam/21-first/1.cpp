#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>


using namespace std;

string s;
const int delta = 29123;

int process(long long x) 
{
	int y = 0;
	for (x = x / 2; x > 1; x = x / 2) 
		y = y + y +  (x + 1) % 2;
  	return y;
}

int bin(int a)
{
	while(a != 0)
	{
		s.insert(s.begin(), (a % 2) + '0');
		a /= 2;
	}
	cout << s << endl;
}

long long re(string a)
{
	long long sum = 0;
	for(int i = 0; i < a.length(); i++)
		sum = sum * 2 + (a[i] - '0');
	cout << sum << endl;
}

int main()
{
	/*bin(delta * delta);
	reverse(s.begin(), s.end());
	for(int i = 0; i < s.length(); i++)
		if(s[i] == '0')
			s[i] = '1';
		else
			s[i] = '0';
	cout << s << endl;
	s.insert(s.begin(), '1');
	s.insert(s.end(), '0');
	re(s);
	*/
	cout << delta * delta << endl;
	cout << process(3075549016) << endl;


			


}