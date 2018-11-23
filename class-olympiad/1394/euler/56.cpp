#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
using namespace std;

string s;

int sum()
{
	int sum1 = 0;
	for(int i = 0;i < s.length(); i++)
		sum1 += int(s[i]) - 48;
	return sum1;
}
int pow(int a,int b)
{
	s .clear();
	for(int i = a; i != 0; i /= 10)
		s += i % 10 + 48;
	long long int baghi = 0;
	bool flag = true;
	for(int j = 1 ; j < b; j++)
	{
		cout << s;
		for(int i = 0; i < s.length() || baghi != 0; i++)
		{
			if(i == s.length())
				flag = false;
			if(flag)
			{
				b += int(s[i] - 48) * b;
			}
			if(i == s[i])
				s +=b % 10 + 48;
			else
				s[i] = b % 10 + 48;
			b /= 10; 
			cout <<"  " <<  s << "  ";
		}
		cout << endl;
	}
}

int main()
{
	int result = 0;
	for (int a = 99; a > 0; a--) 
	{	
    	for (int b = 99; b > 0; b--)
    	{
    		pow(a,b);
    		//cout << s << endl;
    		if(sum() > result)
    			result = sum();
    	}
    }
    cout << result << endl;
}