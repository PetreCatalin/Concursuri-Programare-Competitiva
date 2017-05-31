#include <iostream>

using namespace std;

long n,a[105],i,minim,nr,maxim,j;

int main()
{
    cin>>n;
    for (i=1;i<=n;++i)
        cin>>a[i];
    minim=0;
    minim=1005;
    for (i=2;i<=n-1;++i) {
        maxim=0;
        for (j=1;j<=i-1;++j) {
            nr=a[j+1]-a[j];
            if (nr>maxim) maxim=nr;
        }
        nr=a[i+1]-a[i-1];
        if (nr>maxim) maxim=nr;
        for (j=i+1;j<=n-1;++j) {
            nr=a[j+1]-a[j];
            if (nr>maxim) maxim=nr;
        }
        if (maxim<minim) minim=maxim;
    }

    cout<<minim;

    return 0;
}
