#include <iostream>

using namespace std;

int n,m,i,j,maxim,v[10005],nr1,x,nr2,minim;

int main()
{
    cin>>n>>m;
    while (n!=0 &&m!=0) {
            maxim=0;
            minim=10005;
            for (i=1;i<=n;++i)
                for (j=1;j<=m;++j) {
                    cin>>x;
                    ++v[x];
                    if (x>maxim) maxim=x;
                    if (x<minim) minim=x;
                }

            nr1=1;nr2=1;
            for (i=minim;i<=maxim;++i) {
                if (v[i]>nr1) {nr2=nr1;nr1=v[i];}
                else
                if (v[i]>nr2) nr2=v[i];
            }

            for (i=minim;i<=maxim;++i)
                if (nr2==v[i]) cout<<i<<' ';

            cout<<'\n';
            for (i=minim;i<=maxim;++i)
                if (v[i]!=0) v[i]=0;

            cin>>n>>m;
    }

    return 0;
}
