#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	int n,k;
	cin >> n >> k;
	int w = n % k;
	if(w == 0)
		w = k;
	for(int i = 0; i < k; i++)
	{
		cin >> s;
		if(i == w - 1)
			cout << s << endl;
	}
	
}