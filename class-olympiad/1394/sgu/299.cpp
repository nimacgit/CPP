#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


string s[1000 + 10];
string so[1000 + 10][1000 + 10];

string  b;



bool istri(int i, int j, int k)
{
	if(so[i][j].length() == 0)
	{
		b = s[i];
		for(int l = 0; l < s[j].length(); l++)
		{
			if(l >= b.length())
			{
				b += s[j][l];
			}
			else
				if(b[l] > 47)
					b[l] += s[j][l] - 48;
				else
					b[l] += s[j][l];
			if(b[l] > 9 + 48)
			{
				b[l] -= 10;
				if(l + 1 == b.length())
					b += '1';
				else
					b[l + 1] += 1;
			}
		}
		so[i][j] = b;
	}
	if(so[i][j].length() < s[k].length())
		return false;
	//cout << b << endl;
	if(s[k].length() == so[i][j].length())
	{
		//cout << " b= " << b << " s[k] " << s[k] << endl;
		reverse(s[k].begin(), s[k].end());
		reverse(so[i][j].begin(), so[i][j].end());
		if(s[k] >= so[i][j])
		{
			reverse(so[i][j].begin(), so[i][j].end());
			reverse(s[k].begin(), s[k].end());

			return false;
		}
		reverse(so[i][j].begin(), so[i][j].end());
		reverse(s[k].begin(), s[k].end());

	}
	return true;
}


int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> s[i];
		reverse(s[i].begin(), s[i].end());
	}

	for(int i = 0; i < n ; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			for(int k = j + 1; k < n; k++)
			{
				//cout << s[j].length() << " " << s[i].length() << " " << s[k].length() << endl;
			//	cout << (s[j].length() - s[k].length() + 2 > 0  ) << endl;
				if((s[j].length() - s[k].length() + 2 > 0) || (s[i].length() - s[k].length() + 2 > 0) && (s[k].length() - s[j].length() + 2 > 0) || (s[i].length() - s[j].length() + 2 > 0) &&(s[k].length() - s[i].length() + 2 > 0) || (s[j].length() - s[i].length() + 2 > 0))
					if(istri(i, j, k) && istri(j, k, i) && istri(i, k, j))
					{
						reverse(s[i].begin(),s[i].end());
						reverse(s[j].begin(),s[j].end());
						reverse(s[k].begin(),s[k].end());
						cout << s[i] << " " << s[j] << " " << s[k] << endl;
						return 0;
					}
			}
		}
	}
	cout << "0 0 0" << endl;

	
}