#include <iostream>
#include <string>
#include <vector>

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

	bool help_is_less(Bignumber second)
	{
		if(digits.size() != second.digits.size())
			return (digits.size() < second.digits.size());
		for(int i = second.digits.size() - 1; i >= 0; i--)
			if(second.digits[i] != digits[i])
				return (digits[i] < second.digits[i]);
		return false;
	}

	bool help_is_greater(Bignumber second)
	{
		if(digits.size() != second.digits.size())
			return (digits.size() > second.digits.size());
		for(int i = second.digits.size() - 1; i >= 0; i--)
			if(second.digits[i] != digits[i])
				return (digits[i] > second.digits[i]);
		return false;
	}

	bool islessthan(const Bignumber &second)
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
	
};


int main()
{
	Bignumber a(2);
	long long sum = 0;
	for(int i = 1; i < 1000; i++)
		a = a + a;
	for(int i = a.digits.size() - 1; i >= 0; i--)
		sum += a.digits[i];
	cout << sum << endl;
}