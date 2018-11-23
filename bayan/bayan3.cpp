#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    long long int n;
    cin>>n;
    string na[n+1][6];
    char cha;
    long long int chan;
    long long  int chant;
    for(long long int i=1; i<=n; i++)
    {
        for(long long int j=0; j<6; j++)
            cin>>na[i][j];
        cin>>chant;
        for(long long int l=0; l<chant; l++)
        {
            cin>>cha;
            cin>>chan;
            chan=chan%4;
            for(long long int k=0; k<chan; k++)
            {
                if(cha=='X')
                {
                    swap(na[i][0],na[i][2]);
                    swap(na[i][2],na[i][1]);
                    swap(na[i][2],na[i][5]);
                }
                if(cha=='Y')
                {
                    swap(na[i][1],na[i][4]);
                    swap(na[i][1],na[i][2]);
                    swap(na[i][1],na[i][3]);
                }
                if(cha=='Z')
                {

                    swap(na[i][0],na[i][4]);
                    swap(na[i][0],na[i][5]);
                    swap(na[i][0],na[i][3]);
                }

            }

        }
    }
    ofstream o;
    o.open("34.out",ios::out);
    for(long long int i=1; i<=n; i++)
    {
        for(long long int j=0; j<6; j++)
        {
            o<<na[i][j];
            o<<" ";
        }
        o<<endl;
    }


}

