#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
vector <int> text;

bool isletter(char c)
{
	if((c >= 65 && c < 97) || (c > 96 && c < 123) || (c > 32 && c < 65) || c == 32)
		return true;
	else
		return false;
}


int main()
{
	for(int temp = 2; temp != -2;)
	{
		cin >> temp;
		if(temp != -2)
		{
			v.push_back(temp);
		}
	}
	cout << endl;
	for(int i = 97; i < 123; i++)
	{
		for(int j = 97; j < 123; j++)
		{
			for(int k = 97; k < 123; k++)
			{
				bool flag = true;
				for(int l = 0; l < v.size(); l++)
				{
					if(l % 3 == 0)
					{
						if(isletter(v[l]^i))
							flag = true;
						else
						{
							flag = false;
							l = v.size();
						}
					}
					else
					{
						if(l % 3 == 1)
						{
							if(isletter(v[l]^j))
								flag = true;
							else
							{
								flag = false;
								l = v.size();
							}
						}
						else
						{
							if(isletter(v[l]^k))
								flag = true;
							else
							{

								flag = false;
								l = v.size();
							}
						}
					}
				}
				if(flag == true)
					cout << char(i) << char(j) << char(k) << endl;
			}
		}
	}
	int sum = 0;
	for(int i = 0; i < v.size(); i++)
	{
		if(i % 3 == 0)
		{
			sum += v[i]^103;
		}
		else
		{
			if(i % 3 == 1)
			{
				sum += v[i]^111;
			}
			else
			{
				sum += v[i]^100;
			}
		}
	}
	cout << sum << endl;
}