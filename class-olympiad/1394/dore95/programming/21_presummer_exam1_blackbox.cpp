#include <iostream>
using namespace std;

// The mysterious function inside the blackbox!
int process(long long x) {
  int y = 0;
  if (x % 2) return -1;
  for (x = x / 2; x > 1; x = x / 2) {
    int b = (x + 1) % 2;
    int k = 0;
    for (int i=y+2; i>2; i--)
      k++;
    y += k;
    y += b;
  }
  return y;
}

int main() {
  long long alpha; // the input number

  // take alpha from the keyboard
  cin >> alpha;
  
  // proccess the input using the process() function
  int output = process(alpha);
  
  // pass the result to the LOCK of the BIG ENTRANCE DOOR
  cout << output << endl;

  return 0;
}
