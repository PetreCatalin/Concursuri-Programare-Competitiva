#include <bits/stdc++.h>

using namespace std;

long long i,n,p,q,v[105],x,nr1,nr2,n1;
char s[105];

int main()
{
    cin>>n>>p>>q;
    cin>>s;
    x=0;
    while (x+p<=n) {
            x+=p;
            v[x]=x/p;
    }

    v[0]=0;
    for (i=0;i<=n;++i)
        if ((v[i]!=0 ||i==0) &&i+q<=n &&v[i+q]==0) v[i+q]=v[i]+1;

    if (v[n]==0) cout<<"-1";
    else {
            n1=n;
            cout<<v[n]<<'\n';
            while (n%p!=0) {
                    n-=q;
                    ++nr2;
            }
            nr1=n/p;

            for (i=0;i<=p*nr1-1;++i) {
                cout<<s[i];
                if ((i+1)%p==0) cout<<'\n';
            }
            x=0;
            for (i=p*nr1;i<=n1-1;++i) {
                cout<<s[i];++x;
                if (x%q==0) {x=0;cout<<'\n';}
            }
    }
    return 0;
}
