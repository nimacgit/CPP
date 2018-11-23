#include <iostream>
#include <string>
#include <time.h>

using namespace std;

int main()
{
    string s;
    getline(cin,s);
    for(int i=0; i<s.length(); i++)
       s[i]+=7;
    cout<<s;
    cin>>s;
}
