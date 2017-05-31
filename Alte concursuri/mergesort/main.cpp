#include <iostream>

using namespace std;

long a[100],n,i;

inline void mergesort(long st,long dr)
{
    if (st==dr) return;
    long mij=(st+dr)/2;
    mergesort(st,mij);
    mergesort(mij+1,dr);

    long nr1,nr2,b[100],nr;
    nr1=st;nr2=mij+1;nr=st-1;
    while (nr1<=mij &&nr2<=dr) {
        if (a[nr1]<a[nr2]) {nr++;b[nr]=a[nr1];nr1++;}
        else
        {
            nr++;b[nr]=a[nr2];nr2++;
        }
    }

    while (nr1<=mij) {nr++;b[nr]=a[nr1];nr1++;}
    while (nr2<=dr) {nr++;b[nr]=a[nr2];nr2++;}

    for (long i=st;i<=dr;i++)
        if (a[i]!=b[i]) a[i]=b[i];
}

int main()
{
    cin>>n;
    for (i=1;i<=n;i++)
        cin>>a[i];

    mergesort(1,n);

    for (i=1;i<=n;i++)
        cout<<a[i]<<' ';

    return 0;
}
