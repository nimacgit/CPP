#include <iostream>
#define SZ length()
using namespace std;
const int n = 1389;
const int delta = 90907;
string n2b(int x) {
 string s;
 for(; x; x/=2)
 s = string(1, '0'+(x%2)) + s;
 return s;
}
int main() {
 string r = "";
 for (int i=1; i<=n; i++) {
 string s = n2b(i);
 for (int k = max(0, (int)r.SZ-(int)s.SZ);
 k<(int)r.SZ; k++) {
 if (r.substr(k) == s.substr(0, r.SZ - k)) {
 r += s.substr(r.length() - k);
 goto nexti;
 }
 }
 r += s;
 nexti: ;
 }
 long long ans = r.length() * 1389;
 cout << (ans % delta) << endl;
 return 0;
}