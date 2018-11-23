#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main()
{
	srand(time(NULL));
	ofstream o;
	o.open("inp", ios:: out);
	o << 100000 << " " << 500 << endl;
	for(int i = 1; i <= 100000 ; i++)
		o << rand() % 1000000 << " " << rand() % 1000000 + 1 << endl;
}
