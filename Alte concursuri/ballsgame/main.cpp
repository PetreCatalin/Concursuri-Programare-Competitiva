#include <iostream>

using namespace std;

int n,k,x,v[105],c[105],t,cul[105],nr,i,r,maxim,st,dr;

int main()
{
    cin>>n>>k>>r;
    for (i=1;i<=n;i++)
        cin>>v[i];
    x=v[1];nr=1;
    for (i=2;i<=n;i++) {
        if (v[i]==x) nr++;
        else {
            t++;
            c[t]=nr;
            cul[t]=x;
            x=v[i];
            nr=1;
        }
    }
    t++;
    c[t]=nr;
    cul[t]=x;

   /* for (i=1;i<=t;i++)
        cout<<c[i]<<' ';
    cout<<'\n';
    for (i=1;i<=t;i++)
        cout<<cul[i]<<' '; */

    maxim=0;
    for (i=1;i<=t;i++) {
        nr=0;
        if (cul[i]==r &&c[i]>=2) {
            nr=nr+c[i];
            st=i-1;dr=i+1;
            while (st>=1 &&dr<=t) {
                if (cul[st]==cul[dr] &&c[st]+c[dr]>=3) {
                    nr=nr+c[st]+c[dr];
                    st=st-1;
                    dr=dr+1;
                }
                else break;
            }
            if (nr>maxim) maxim=nr;
    }
    }

    cout<<maxim;

    return 0;
}
