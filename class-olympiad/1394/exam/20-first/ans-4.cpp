#include <iostream>
using namespace std;
const int n = 60;
const int delta = 90907;
int findWinner(int start) {
	bool a[n+1];
	for (int i=1; i<=n; i++) a[i] = true;
		int x = start; a[x] = false;
	int alive = n-1;
	for (; alive != 1; ) {
		int jump = x;
		for (int i=1; i<=jump; i++)
			do {
				x++; if (x == n+1) x = 1;
			} while (!a[x]);
			a[x] = false; alive--;
		}
		for (int i=1; i<=n; i++)
			if (a[i])
				return i;
			return -1;
}
int main() {
	int t = 1;
	for (int start=1; start<=n; start++)
	{
		int temp = findWinner(start);
		t = (t*temp) % delta;
		cerr << temp << endl;
	}
	cout << (t) << endl;
	return 0;
}