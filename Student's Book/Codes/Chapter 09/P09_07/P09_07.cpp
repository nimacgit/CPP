#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
bool isprime(int x)
{
   int i;
   bool p=true;
   for(i=2;i<=sqrt(x);i++)
      if(x%i==0)
         p=false;
   return p;
}
int main()
{
   int i,n;
   cout<<"Enter n:";
   cin>>n;
   for(i=2;i<=n;i++)
      if(isprime(i))
         cout<<i<<" is prime."<<endl;
   getch();
   return 0;
}
