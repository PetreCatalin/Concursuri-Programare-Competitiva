#include <iostream>

using namespace std;

long long n,nr,x,ap[15],i,j;
char c;

int main()
{
    cin>>n;
    for (i=1;i<=n;++i) {
        cin>>c;
        x=c-'0';
        if (x==2) ++ap[2];
        if (x==3) ++ap[3];
        if (x==4) {ap[2]=ap[2]+2;++ap[3];}
        if (x==5) ++ap[5];
        if (x==6) {++ap[5];++ap[3];}
        if (x==7) ++ap[7];
        if (x==8) {++ap[7];ap[2]=ap[2]+3;}
        if (x==9) {++ap[7];ap[3]=ap[3]+2;++ap[2];}
    }

    for (i=9;i>=2;--i)
        for (j=1;j<=ap[i];++j)
            cout<<i;

    return 0;
}
