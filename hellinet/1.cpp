#include <vector>
#include <iostream>
#include <cmath>
using namespace std;



int main()
{
    string s;
    cin >> s;
    int m = 1;
    int i=0;
    for (i = 0;i<s.length();)
    {
        if (s[i]=='O')
        {
            s[i]='X';
        }
        else
        if (s[i]=='X')
        {
            s[i]='O';
            m*=-1;
        }
        i+=m;
        if(i==-1)
            cout<<"YES"<<endl;
        if(i== s.length())
            cout<<"NO"<<endl;
    }
}


