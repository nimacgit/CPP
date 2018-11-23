#include <iostream>
#include <string>

using namespace std;

int start = 0;
int endstr;
int n, sum = 0;
string str;
bool fard;

int find(int star, int en)
{
	for(int i = en; i > star; i--)
	{
		if(str[star] == str[i])
		{
			return i;
		}
	}
	//cout << " i " << str[star] << " " << star << " " << en << endl;
	return -2;
}

bool check()
{
	fard = false;
	sum = 0;
	start = 0;
	endstr = str.length() - 1;
	while(start <= endstr)
	{
		if(find(start, endstr) == -2)
		{
			if(!fard)
			{
				fard = true;
				for(int k = start; k < str.length() / 2; k++)
					sum++;
				endstr++;
			}
			else
			{
				return false;
			}
		}
		else
		{
			for(int k = find(start, endstr); k < endstr; k++)
			{
				swap(str[k], str[k + 1]);
				sum++;
			}
		}
		start++;
		endstr--;
	}
	return true;
}

int main()
{
	cin >> n;
	while(n)
	{
		cin >> str;
		if(check())
			cout << sum << endl;
		else
			cout << "Impossible" << endl;
		n--;
	}
}