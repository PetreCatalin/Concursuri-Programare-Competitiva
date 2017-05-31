#include <bits/stdc++.h>

using namespace std;

long v[100005],p[100005],n,i,j,nr,numar;
long long s,x,k,pro;
double prob[100005],pr;

long long cmmdc(long long a,long long b)
{
    long long r;
    while (b!=0) {
            r=a%b;
            a=b;
            b=r;
    }
    return a;
}

int main()
{
    ifstream f("porcjoc.in");
    ofstream g("porcjoc.out");
    f>>n;
    for (i=1;i<=n;++i) {
            f>>v[i]>>p[i];
            s+=p[i];
    }

    for (i=1;i<=n;++i)
        prob[i]=(double) p[i]/s;

    for (i=1;i<=n;++i)
        for (j=1;j<=n;++j)
        if (v[i]!=v[j] || (v[i]==1&&v[j]==1)) {
                nr=cmmdc(v[i],v[j]);
                if (nr==1)
                    pr+=prob[i]*prob[j];
        }

    x=1;
    while (floor(pr)!=pr) {
            pr*=10;
            x*=10;
            pro=(long long) pr;
            if (pro%10==(pro%100)/10 &&pro%10==(pro%1000)/100 &&pro%10==(pro%10000)/1000) break;
    }

    --x;

    pro=(long long) pr;
    k=cmmdc(pro,x);
    g<<pro/k<<'/'<<x/k;

    f.close();
    g.close();
    return 0;
}
