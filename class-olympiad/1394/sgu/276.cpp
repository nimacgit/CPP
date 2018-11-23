#include <iostream>

using namespace std;

int main()
{
	int a,b;
	cin >> a >> b;
	if(a > b)
		cout << "0" << endl;
	else
		if(a == b)
			cout << "0" << endl;
		else if(a > b - 300)
			cout << "1" << endl;
			else if( a + 900 > b )
				cout << "2" << endl;
				else if(a + 1800 > b)
				cout << "3" << endl;
				else
					cout << "4" << endl;
	
}