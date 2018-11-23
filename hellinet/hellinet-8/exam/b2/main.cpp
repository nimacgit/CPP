#include <iostream>

using namespace std;

int main()
{
    for(int i=1,k=1;2;i++)
    {
        if(i%2==1)
        {
            for(int j=1;j<=i;k++)
                cout<<k;
        }
        else
            k+=i;
    }
    return 0;
}
