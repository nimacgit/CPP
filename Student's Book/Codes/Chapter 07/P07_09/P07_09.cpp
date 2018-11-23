#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
   int i;
   char ch;
   string s;
   cout<<"Enter your string:";
   getline(cin,s);
   cout<<"Enter your separator character:";
   cin>>ch;
   for(i=0;i<s.length();i++)
       if(s[i]==ch)
          cout<<endl;
       else
          cout<<s[i];
   getch();
   return 0;
}
