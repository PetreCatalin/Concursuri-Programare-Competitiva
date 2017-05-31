#include <iostream>

using namespace std;

int n,m,ok,ok1,i,j,nr,a[105][105],b[105][105],l[105],c[105];

int main()
{
    cin>>n>>m;
    ok=0;
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++) {
            cin>>b[i][j];
        if (b[i][j]==1) if (ok==0) ok=1;
        }

    if (ok==0) {
        cout<<"YES"<<'\n';
        for (i=1;i<=n;i++) {
            for (j=1;j<=m;j++)
                cout<<'0'<<' ';
            cout<<'\n';
        }
    }

    if (ok==1) {
        for (i=1;i<=n;i++) {
            nr=0;
            for (j=1;j<=m;j++)
            if (b[i][j]==1) ++nr;
            if (nr==m) l[i]=1;
        }

        for (j=1;j<=m;j++) {
            nr=0;
            for (i=1;i<=n;i++)
            if (b[i][j]==1) ++nr;
            if (nr==n) c[j]=1;
        }

        ok1=1;
        for (i=1;i<=n;++i)
            for (j=1;j<=m;++j)
                if (b[i][j]==1 && l[i]==0 &&c[j]==0) {ok1=0;break;}

        if (ok1==0) cout<<"NO";
        else {
            cout<<"YES"<<'\n';
            for (i=1;i<=n;i++)
                for (j=1;j<=m;j++)
                if (l[i]==1 &&c[j]==1) a[i][j]=1;

            for (i=1;i<=n;++i) {
                for (j=1;j<=m;++j)
                cout<<a[i][j]<<' ';
            cout<<'\n';
            }
        }
    }

    return 0;
}
