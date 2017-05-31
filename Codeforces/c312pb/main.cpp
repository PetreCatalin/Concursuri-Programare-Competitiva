#include <iostream>

using namespace std;

long n,i,x,ap[1000005],a[1000005],b[1000005],maxim,minim,m,st,dr;

int main()
{
    cin>>n;
    maxim=0;
    minim=1000005;
    for (i=1;i<=n;++i) {
            cin>>x;
            ++ap[x];
            if (a[x]==0) a[x]=i;
            b[x]=i;
            if (x>maxim) maxim=x;
            if (x<minim) minim=x;
    }

    for (i=minim;i<=maxim;++i) {
        if (ap[i]>m) {
                m=ap[i];
                st=a[i];
                dr=b[i];
        }
        if (ap[i]==m) {
                if (b[i]-a[i]<dr-st) {
                        st=a[i];
                        dr=b[i];
                }
        }
    }

    cout<<st<<' '<<dr;

    return 0;
}
