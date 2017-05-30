#include <bits/stdc++.h>

using namespace std;

long i,n,v,j,k,nr,ok,maxim,m;
char s[1005],x1,x2;

struct ef{
    char s[1005];
}st[101];

int main()
{
    cin>>n;
    for (i=1;i<=n;++i)
        cin>>st[i].s;

        for (j=1;j<=26;++j) {
            x1='a'+j-1;
            for (k=j;k<=26;++k) {
                x2='a'+k-1;
                m=0;
                for (i=1;i<=n;++i) {
                nr=0;ok=1;
                for (v=0;v<strlen(st[i].s);++v) {
                    if (st[i].s[v]!=x1 && st[i].s[v]!=x2) {ok=0;break;}
                    else
                    ++nr;
                }
                if (ok==1) m+=nr;
            }
            if (m>maxim) maxim=m;
        }
    }

    cout<<maxim;
    return 0;
}
