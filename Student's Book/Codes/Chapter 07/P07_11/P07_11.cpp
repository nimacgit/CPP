#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
   int i,j,m,n,a[10][10];
   for(i=0;i<10;i++)
      for(j=0;j<10;j++)
         a[i][j]=(i+1)*(j+1);
   cout<<"Enter m,n:";
   cin>>m>>n;
   for(i=0;i<m;i++)
   {
      for(j=0;j<n;j++)
         cout<<a[i][j]<<"\t";
      cout<<endl;
   }
   getch();
   return 0;
}
