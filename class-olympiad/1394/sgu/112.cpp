#include <iostream>
#include <string>

using namespace std;

string first, second, temp;
int a,b;

void reva()
{
	temp.clear();
	for(int i = 0; i < first.length(); i++)
		temp += first[first.length() - i - 1];
	first = temp;
}
void revb()
{
	temp.clear();
	for(int i = 0; i < second.length(); i++)
		temp += second[second.length() - i - 1];
	second = temp;
}
void mula()
{
	int baghi = 0;
	bool flag = true;
	for(int i = 0; baghi != 0 || i < first.length(); i++)
	{
		if(i == first.length())
			flag = false;
		if(flag)
			baghi += int(first[i] - 48) * a;
		if(i < first.length())
			first[i] = char((baghi % 10) + 48);
		else
			first += char((baghi % 10) + 48);
		baghi /= 10;
	}

}
void mulb()
{
	int baghi = 0;
	bool flag = true;
	for(int i = 0; baghi != 0 || i < second.length(); i++)
	{
		if(i == second.length())
			flag = false;
		if(flag)
			baghi += int(second[i] - 48) * b;
		if(i < second.length())
			second[i] = baghi % 10 + 48;
		else
			second += baghi % 10 + 48;
		baghi /= 10;
	}
}

void kamfirs()
{
	int i = 0;
	for(; i < second.length(); i++)
	{
		first[i] -= (int(second[i]) - 48);
		if(int(first[i]) < 48)
		{
			first[i] += 10;
			first[i + 1]--;
		}
	}
	while(int(first[i]) < 48)
	{
		first[i] += 10;
		first[i + 1]--;
		i++;
	}
	while(first[first.length() - 1] == '0')
		first.erase(first.length() - 1, first.length() - 1);
	reva();
	cout << first << endl;
}

void kamsec()
{
	int i = 0;
	for(; i < first.length(); i++)
	{
		second[i] -= (int(first[i]) - 48);
		if(int(second[i]) < 48 )
		{
			second[i + 1]--;
			second[i] += 10;
		}
	}
	while(i < second.length() &&  int(second[i]) < 48)
	{
		second[i] += 10;
		second[i + 1]--;
		i++;
	}
	while(second[second.length() - 1] == '0')
		second.erase(second.length() - 1, second.length() - 1);
	revb();
	cout << second << endl;
}


void menha()
{
	if(first == second)
	{
		cout << "0" << endl;
	}
	else
	{ 
		if(first.length() > second.length())
		{
			kamfirs();
		}
		else 
		{
			if(second.length() > first.length())
			{
				cout << "-";
				kamsec();
			}
			else 
			{
				if(first > second)
				{
					kamfirs();
				}
				else
				{
					cout << "-";
					kamsec();
				}
			}
		}
	}
}


int main()
{
	cin >> a >> b;
	first.clear();
	for(int temp = a; temp != 0; temp /= 10)
		first += char((temp % 10) + 48);
	second.clear();
	for(int temp = b; temp != 0; temp /= 10)
		second += char((temp % 10) + 48);
	for(int i = 1; i < b; i++)
		mula();
	for(int i = 1; i < a; i++)
		mulb();
	menha();
}