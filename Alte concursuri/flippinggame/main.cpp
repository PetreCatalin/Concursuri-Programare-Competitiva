#include <iostream>

using namespace std;

int n,i,v[105],j,maxim,inc,sf,nr0,nr1,k,x;

int main()
{
    cin>>n;
    for (i=1;i<=n;i++)
        cin>>v[i];

    if (n==1) cout<<1-v[1];
    else {
    maxim=-1;
    for (i=1;i<=n;i++)
        for (j=i;j<=n;j++) {
            nr0=0;nr1=0;
            for (k=i;k<=j;k++) {
                if (v[k]==0) nr0++;
                if (v[k]==1) nr1++;
                if (nr0-nr1>maxim) {maxim=nr0-nr1;inc=i;sf=j;x=nr0;}
            }
        }

    if (maxim==-1) cout<<n-1;
    else {

    for (i=1;i<=inc-1;i++)
        if (v[i]==1) x++;
    for (i=sf+1;i<=n;i++)
        if (v[i]==1) x++;

    cout<<x;
    }
    }

    return 0;
}
