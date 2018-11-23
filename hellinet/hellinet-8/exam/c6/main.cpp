#include <iostream>
#include <vector>
using namespace std;
void mov(int & i,int & j,int po)
{
    if (po ==1)
    {
        i--;
        j--;
    }
    if(po==2)
    {
        i--;
    }
    if(po==3)
    {
        i--;
        j++;
    }
    if(po==4)
    {
        j++;
    }
    if(po==5)
    {
        i++;
        j++;
    }
    if(po==6)
    {
        i++;
    }
    if(po==7)
    {
        i++;
        j--;
    }
    if(po==8)
    {
        j--;
    }
}
int main()
{

    int n,m;
    cin >> n >> m;
    char city[n][m];
    int k1=-1,k2=-1,d1=-1,d2=-1,s=0;
    int po=2;
    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<m; j++)
        {
            cin >> city[i][j];
            if(city[i][j] == 'K')
            {
                k1 = i;
                k2 = j;
            }
            else if(city[i][j]=='D')
            {
                d1 = i;
                d2 = j;
            }
        }
    }
    int di=k1,dj=k2;
    int kj,ki;
    cout<<k1<<" "<<di<<endl;
    while ((k1 != di) || (k2 != dj) || s==0)
    {

        ki=k1;
        kj=k2;
        mov(kj,ki,po);
        if(city[ki][kj]=='X')
        {
            po++;
            if(po>8)
                po-=8;
        }
        else
        {

            if(( po==1 || po ==2 || po ==3)&& k2==0)
            {
                po++;
            }
            else if((po==1 || po==7 || po==8) && k1==0)
            {
                po++;
            }
            else if((po==3 || po==5 || po==4) && k1==m-1)
            {
                po++;
            }
            else if((po==5 || po==6 || po==7) && k2==n-1)
            {
                po++;
            }
            else
            {

                mov(k1,k2,po);
                cout<<"a ";
                cout<<k1<<" "<<di<<endl;
                s++;
                if(d1==k1 && d2==k2)
                    cout<<s;
            }
        }
    }

}
