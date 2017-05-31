#include <iostream>

using namespace std;

long n,x,y,i,v1[100005],a[100005],b[100005],nr;

int main()
{
    cin>>n;
    for (i=1;i<=n;i++) {
        cin>>a[i]>>b[i];
        ++v1[a[i]];
    }

    for (i=1;i<=n;i++) {
        nr=n-1;
        nr+=v1[b[i]];
        cout<<nr<<' '<<(n-1)*2-nr<<'\n';
    }

    return 0;
}
