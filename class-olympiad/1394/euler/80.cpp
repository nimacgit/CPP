#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>

using namespace std;


class Bignumber
{
public:
	vector <int> digits;
	bool manfi;
	Bignumber()
	{
		manfi = false;
		digits.push_back(0);
	}
	Bignumber(int num)
	{
		manfi = false;
		if(num == 0)
			digits.push_back(0);
		if(num < 0)
		{
			manfi = true;
			num *= -1;
		}
		while(num > 0)
		{
			digits.push_back(num % 10);
			num /= 10;
		}
	}



	Bignumber(string s)
	{
		int end = 0;
		manfi = false;
		if(s[0] == '-')
		{
			manfi = true;
			end++;
		}
		for(int i = s.length() - 1; i >= end; i--)
			digits.push_back(s[i] - '0');
	}



	Bignumber abs()
	{
		Bignumber temp = *this;
		temp.manfi = false;
		return temp;
	}




	Bignumber helpadd(Bignumber second)
	{
		Bignumber temp;
		int minsize = min(digits.size(), second.digits.size());
		int i = 0;
		for(; i < minsize; i++)
		{
			temp.digits[i] += digits[i] + second.digits[i];
			temp.digits.push_back(temp.digits[i] / 10);
			temp.digits[i] %= 10;
		}
		for(int j = i; j < second.digits.size(); j++)
		{
			temp.digits[j] += second.digits[j];
			temp.digits.push_back(temp.digits[j] / 10);
			temp.digits[j] %= 10;
		}
		for(int j = i; j < digits.size(); j++)
		{
			temp.digits[j] += digits[j];
			temp.digits.push_back(temp.digits[j] / 10);
			temp.digits[j] %= 10;
		}
		if(temp.digits[temp.digits.size() - 1] == 0)
			temp.digits.pop_back();
		return temp;
	}


	Bignumber helpminus(Bignumber second)
	{
		Bignumber temp = *this;
		int i = 0, carry = 0;
		for(; i < second.digits.size(); i++)
		{
			temp.digits[i] -= second.digits[i] + carry;
			carry = 0;
			if(temp.digits[i] < 0)
			{
				carry = 1;
				temp.digits[i] += 10;
			}
		}
		while(carry > 0)
		{
			temp.digits[i]--;
			carry = 0;
			if(temp.digits[i] < 0)
			{
				temp.digits[i] += 10;
				carry = 1;
			}
			i++;
		}
		while(*(temp.digits.end() - 1) == 0 && temp.digits.size() > 1)
			temp.digits.pop_back();

		return temp;
	}

	bool help_is_less(Bignumber second) const
	{
		if(digits.size() != second.digits.size())
			return (digits.size() < second.digits.size());
		for(int i = second.digits.size() - 1; i >= 0; i--)
		{
			if(second.digits[i] != digits[i])
				return (digits[i] < second.digits[i]);
		}
		return false;
	}

	bool help_is_greater(Bignumber second) const
	{
		if(digits.size() != second.digits.size())
			return (digits.size() > second.digits.size());
		for(int i = second.digits.size() - 1; i >= 0; i--)
		{
			if(second.digits[i] != digits[i])
				return (digits[i] > second.digits[i]);
		}
		return false;
	}

	bool islessthan(const Bignumber & second) const
	{
		if(manfi)
		{
			if(second.manfi)
				return help_is_greater(second);
			else
				return true;
		}
		else
		{
			if(second.manfi)
				return false;
			else
				return help_is_less(second);
		}
	}

	void swap(Bignumber & second)
	{
		Bignumber temp = *this;
		manfi = second.manfi;
		digits = second.digits;
		second = temp;
	}



	Bignumber operator + (const Bignumber & inp) const
	{
		Bignumber temp;
		Bignumber first = *this;
		Bignumber second = inp;
		if(inp.manfi == manfi)
		{
			temp = first.abs().helpadd(second.abs());
			temp.manfi = manfi;
			return temp;
		}	
		if(first.help_is_less(second))
			first.swap(second);
		//cerr << " help " << endl;
		//first.print();
		//second.print();
		temp = first.helpminus(second);
		temp.manfi = first.manfi;
		return temp;
	}
	void print()
	{
		if(manfi)
		{
			cout << '-';
		}
		for(int i = digits.size() - 1; i >= 0; i--)
			cout << digits[i];
		cout << endl;
	}


	Bignumber operator - (const Bignumber & second)
	{
		if(second.manfi)
		{
			Bignumber temp = second;
			return (*this + temp.abs());
		}
		if(manfi)
		{
			Bignumber temp = ((this -> abs()) + second);
			temp.manfi = true;
			return temp;
		}
		else
		{
			if(!islessthan(second))
				return helpminus(second);
			Bignumber temp = second;
			temp.manfi = true;
			return temp.helpminus(*this);
		}

	}
};

bool operator == (const Bignumber & inp , const Bignumber & inp2) 
{
	if(inp2.digits.size() != inp.digits.size())
		return false;
	for(int i = 0; i < inp2.digits.size(); i++)
	{
		if(inp2.digits[i] != inp.digits[i])
			return false;
	}
	return true;
}

ostream & operator << (ostream & out, const Bignumber  &a){
	if(a.manfi)
		out << '-';
	for(int  i = a.digits.size() - 1; i >= 0; i --){
		out << a.digits[i];
	}
	return out;
}

istream & operator >> (istream & in, Bignumber  &a){
	string temp;
	in >> temp;
	a.digits.clear();
	int start = 0;
	if(temp[0] == '-')
	{
		a.manfi = true;
		start++;
	}
	else
		a.manfi = false;
	for(int  i = temp.size() - 1; i >= start ; i--){
		 a.digits.push_back(temp[i] - '0');
	}
	return in;
}

bool operator < (const Bignumber & inp , const Bignumber & inp2)
{
	if(inp.islessthan(inp2))
		return true;
	return false;
}
bool operator > (const Bignumber & inp , const Bignumber & inp2)
{
	if(inp2.islessthan(inp))
		return true;
	return false;
}
bool operator >= (const Bignumber & inp , const Bignumber & inp2)
{
	if(inp.islessthan(inp2))
		return false;
	return true;
}
bool operator <= (const Bignumber & inp , const Bignumber & inp2)
{
	if(inp2.islessthan(inp))
		return false;
	return true;
}

Bignumber operator *(const Bignumber & inp,const int times)
{
	Bignumber temp = 0;
	for(int i = 1; i <= times; i++)
		temp = temp + inp;
	return temp;
}
Bignumber operator *(const Bignumber & inp,const Bignumber times)
{
	Bignumber temp = 0;
	for(int i = 1; i <= times; i++)
		temp = temp + inp;
	return temp;
}


Bignumber operator %(const Bignumber & inp , const Bignumber & inp2)
{
	Bignumber temp = inp;
	while(temp > inp2)
		temp = temp - inp2;
	return temp;
}

Bignumber operator /(const Bignumber & inp , const Bignumber & inp2)
{
	Bignumber temp = inp;
	temp = temp - (temp % inp2);
	Bignumber counter = 0;
	while(temp > inp2)
	{
		temp = temp - inp2;
		counter = counter + 1;
	}
	return counter;
}

Bignumber power(Bignumber a, int b)
{
	Bignumber temp(1);
	while(b)
	{
		temp = temp * a;
		b--;
	}
	return temp;
}


const Bignumber limit = power((Bignumber)10, 101);



Bignumber radical(int c)
{
	Bignumber a(5 * c);
	Bignumber b(5);
	while(b < limit)
	{
		if(a >= b)
		{
			a = a - b;
			b = b + (Bignumber)10;
		}
		else
		{
			a = a * 100;
			b = b - 5;
			b = b * 10;
			b = b + 5;
		}
	}
	return b;
}


int findsum(int a)
{
	Bignumber rad = radical(a);
	int sum = 0;
	for(int i = 0; i < 100; i++)
		sum += rad.digits[rad.digits.size() - i - 1];
	return sum;
}




int main()
{
	cout << radical(2) << endl;
	long long sum = 0;
	for(int i = 2; i <= 100; i++)
	{
		cout << i << endl;
		if((double)sqrt(i) != (int)sqrt(i))
			sum += findsum(i);
	}
	cout << sum << endl;
}