#include <iostream>
#include <conio.h>
#include <nodet.h>
using namespace std;
int main()
{
   int i;
   string s;
   cout<<"Enter your string:";
   getline(cin,s);
   for(i=0;i<s.length();i++)
       if(s[i]==chartoupper(s[i]))
          s[i]=chartolower(s[i]);
       else
          s[i]=chartoupper(s[i]);
   cout<<"Converted String:"<<s;
   getch();
   return 0;
}
