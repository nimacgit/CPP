#include <iostream>
#include <string>



using namespace std;

string s, t, p;

int main()
{
	cin >> s >> t;
	p = t;
	bool diff = false;
	for(int i = 0; i < t.length(); i++)
	{
		if(p[i] != s[i])
		{
			if(diff)
			{
				p[i] = s[i];
				diff = false;
			}
			else
				diff = true;
		}
	}
	if(diff)
		cout << "impossible" << endl;
	else
		cout << p << endl;
}