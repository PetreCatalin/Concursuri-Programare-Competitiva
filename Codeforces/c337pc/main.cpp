#include <bits/stdc++.h>

using namespace std;

long long k,nr,p,i,j;
char a[1025][1025];

int main()
{
    cin>>k;
    a[1][1]='+';
    a[1][2]='+';
    a[2][1]='+';
    a[2][2]='*';
    nr=1;p=2;
    if (k==0)
        cout<<'+';
    else
    if (k==1) {
    for (i=1;i<=p;++i) {
        for (j=1;j<=p;++j)
        cout<<a[i][j];
        cout<<'\n';
    }
    }
    else {

    while (nr+1<=k) {
    ++nr;

    for (i=1;i<=p;++i)
        for (j=p+1;j<=p*2;++j)
        a[i][j]=a[i][j-p];

    for (i=p+1;i<=2*p;++i)
        for (j=p+1;j<=p*2;++j)
        a[i][j]=a[i-p][j-p];

    for (i=p+1;i<=2*p;++i)
        for (j=1;j<=p;++j){
        if (a[i-p][j]=='+') a[i][j]='*';
        else
        a[i][j]='+';
        }

    p=p*2;
    }

      for (i=1;i<=p;++i) {
        for (j=1;j<=p;++j)
        cout<<a[i][j];
        cout<<'\n';
    }
    }

    return 0;
}
