#include <iostream>
#include <cmath>

using namespace std;

int a,b,c,putere[100],maxim,cmmmc,i,maxim1,nr;

void subp(int a)
{
    int i;
    i=1;
    while (a!=1) {
            i++;
            if (a%i==0) {
                nr=0;
                if (i>maxim) maxim=i;
            while (a%i==0) {nr++;a=a/i;if (nr>putere[i]) putere[i]=nr;}
        }
    }
}

int main()
{
    cin>>a>>b>>c;

    subp(a);subp(b);subp(c);

    cmmmc=1;
    for (i=2;i<=maxim;i++) {
        if (putere[i]!=0)
        cmmmc=cmmmc*pow(i,putere[i]);
    }

    cout<<cmmmc;

    return 0;
}
