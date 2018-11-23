#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string s;
    getline(cin,s);
    vector <char> b;
    char m,f;
    f=s[0];
    int i=0;
    for(;s[i]!=' ';i++);
    m=s[i+1];
    i++;
    for(;s[i]!=' ';i++);
    i++;
    for(;i<s.length();i++ )
        b.push_back(s[i]);
    b.push_back(' ');
    b.push_back(f);
    b.push_back('.');
    b.push_back(' ');
    b.push_back(m);
    b.push_back('.');
    for(int j=0;j<b.size();j++)
        cout << b[j] ;
    return 0;
}
