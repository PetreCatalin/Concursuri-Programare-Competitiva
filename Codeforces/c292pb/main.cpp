#include <iostream>

using namespace std;

long n,m,a[105],b[105],a1[105],b1[105],i,bi,f1,x,y,ok,nr,nr1;

int main()
{
    cin>>n>>m;
    cin>>bi;
    for (i=1;i<=bi;++i) {
        cin>>x;
        a1[x]=1;
        ++nr1;
    }
    cin>>f1;
    for (i=1;i<=f1;++i) {
        cin>>x;
        b1[x]=1;
        ++nr1;
    }

    x=0;y=0;
    ok=1;nr=0;
    while (ok==1 &&nr1<n+m) {
        if (a1[x]==1 &&b1[y]==0) {b1[y]=1;++nr1;}
        else
        if (a1[x]==0 &&b1[y]==1) {a1[x]=1;++nr1;}
        ++nr;
        x=nr%n;
        y=nr%m;
    if (x==0 &&y==0) {ok=0;break;}
    }

    ok=1;
    for (i=0;i<=n-1;++i)
        if (a1[i]==0) {ok=0;break;}

    if (ok==1) {
        for (i=0;i<=m-1;++i)
            if(b1[i]==0) {ok=0;break;}
    }

    if (ok==1) cout<<"Yes";
    else
    cout<<"No";

    return 0;
}
