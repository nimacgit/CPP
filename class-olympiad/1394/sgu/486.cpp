#include <iostream>
#include <string>

using namespace std;

string num,guess;

int main()
{
	int cow = 0,bull = 0;
	cin >> num >> guess;
	for(int i = 0; i < 4; i++)
	{
		if(guess[i] == num[i])
			bull++;
		else
			for(int j = 0; j < 4; j++)
				if(num[j] == guess[i] && i != j)
					cow++;
	}
	cout << bull << " " << cow << endl;
	
}