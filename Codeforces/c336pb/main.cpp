#include <bits/stdc++.h>

using namespace std;

char a[200005],b[200005];
long long nr,i,rez1,rez,j,x,y,xx,yy,c,nr1;

int main()
{
    cin>>a;
    cin>>b;
    nr=strlen(a);
    for (i=nr-1;i>=0;--i) {
        y+=(b[i]-'0')*pow(2,nr-1-i);
        x+=(a[i]-'0')*pow(2,nr-1-i);
    }

    for (i=1;i<=strlen(b)-nr+1;++i) {
        if (x!=y) {
            rez1=x^y;
            nr1=0;
            while (rez1!=0) {
                    if (rez1%2==1) ++nr1;
                    rez1/=2;
            }
        rez+=nr1;
        }
        y-=(b[i-1]-'0')*pow(2,nr-1);
        y=y*2;
        y+=(b[i+nr-1]-'0');
    }

    cout<<rez;
    return 0;
}

