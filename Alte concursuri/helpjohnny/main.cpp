#include <iostream>

using namespace std;

long t,i,n,a[100005],b[100005],j,k;
long long s;

int main()
{
    cin>>t;
    for (j=1;j<=t;++j) {
            cin>>n;
            for (i=1;i<=n;++i) {
                cin>>a[i]>>b[i];
                for (k=i-1;k>=1;--k)
                    s+=a[i]*b[k]+b[i]*a[k];
            }
            cout<<"Case "<<j<<": "<<s<<'\n';
        s=0;
    }

    return 0;
}
