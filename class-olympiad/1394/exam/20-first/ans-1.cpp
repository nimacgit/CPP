#include <iostream>
using namespace std;
bool isPrime(int x) {
	if (x < 2) return false;
	for (int i=2; i*i<=x; i++)
		if (x % i == 0)
			return false;
		return true;
	}
	const int n = 1389;
	const int delta = 90907;
	int main() {
 bool r[n+1]; // looking to right
 for (int i=0; i<n; i++)
 	r[i] = isPrime(i+1);
 bool changed = true;
 long long t = 0;
 for (t = 0; ; t++) {
 	changed = false;
 	for (int i=0; i<n-1; i++)
 		if (r[i] && !r[i+1])
 			{ swap(r[i], r[i+1]); i++; changed=true; }
 		if (!changed) break;
 	}
 	long long R = t + t*t + t*t*t;
 	cout << (R % delta) << endl;
 	return 0;
 }