#include <iostream>
#include <string>

using namespace std;
string s1,s2;
int n;

int main()
{
	cin >> n;
	cin >> s1 >> s2;
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		if(s1[i] > s2[i])
		{
			if(s1[i] - s2[i] < 9 - (s1[i] - 48) + 1 + (s2[i] - 48) )
			{
				sum += s1[i] - s2[i];
			}
			else
			{
				sum += 9 - (s1[i] - 48) + 1 + (s2[i] - 48);
			}
		}
		else
		{
			if(s2[i] - s1[i] < 9 - (s2[i] -48) + 1 + (s1[i] - 48))
			{
				sum += s2[i] - s1[i];
			}
			else
			{
				sum += 9 - (s2[i] -48) + 1 + (s1[i] - 48);
			}
		}
	}
	cout << sum << endl;

}