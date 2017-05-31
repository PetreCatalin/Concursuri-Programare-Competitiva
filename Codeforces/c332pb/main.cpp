#include <bits/stdc++.h>

using namespace std;

long i,n,m,f[100004],b[100004],v1[100004],v2[100004],ok=1,x[100004];

int main()
{
    cin>>n>>m;
    for (i=1;i<=n;++i) {
        cin>>f[i];
        ++v1[f[i]];
        x[f[i]]=i;
    }
    for (i=1;i<=m;++i) {
        cin>>b[i];
        ++v2[b[i]];
    }

    for (i=1;i<=m;++i)
            if (v1[b[i]]<v2[b[i]]) {ok=0;break;}

    if (ok==0) cout<<"Impossible";
    else {
            for (i=1;i<=m;++i)
                if (v1[b[i]]>1) {ok=2;break;}
    }
    if (ok==2) cout<<"Ambiguity";
    if (ok==1) {
            cout<<"Possible\n";
            for (i=1;i<=m;++i)
                cout<<x[b[i]]<<' ';
    }

    return 0;
}
