#include <iostream>

using namespace std;

char s[5];
int n,i,nr,j,nrp,nrm;

int main()
{
    cin>>n;
    for (i=1;i<=n;i++) {
        cin>>s;
        nrp=0;nrm=0;
        for (j=0;j<=2;j++)
            if (s[j]=='+') nrp++;
            else
            if (s[j]=='-') nrm++;
        if (nrp==2) nr++;
        else
        nr=nr-1;
    }

    cout<<nr;

    return 0;
}
