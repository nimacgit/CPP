#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
   string s;
   cout<<"Enter your name:";
   cin>>s;
   cout<<"Hi "<<s<<"!"<<endl;
   cout<<"Your name has "<<s.length()<<" characters";
   getch();
   return 0;
}
