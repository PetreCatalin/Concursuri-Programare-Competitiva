#include <iostream>
#include <algorithm>

using namespace std;

long v[5],n,i,minim,a[5005],r[5][5005],nr1,nr2,nr3,j;

int main()
{
    cin>>n;
    for (i=1;i<=n;i++) {
        cin>>a[i];
        v[a[i]]++;
        if (a[i]==1) {
            ++nr1;
        r[1][nr1]=i;
        }
         if (a[i]==2) {
            ++nr2;
        r[2][nr2]=i;
        }
         if (a[i]==3) {
            ++nr3;
        r[3][nr3]=i;
        }
    }

    minim=min(v[1],v[2]);
    minim=min(minim,v[3]);
    cout<<minim<<'\n';

    for (j=1;j<=minim;j++) {
        cout<<r[1][j]<<' ';
        cout<<r[2][j]<<' ';
        cout<<r[3][j]<<'\n';
    }

    return 0;
}
