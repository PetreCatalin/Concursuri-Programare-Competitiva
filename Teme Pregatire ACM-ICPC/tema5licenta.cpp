#include <bits/stdc++.h>
 
using namespace std;
 
struct  p
{
    long long x,y;
};
 
long long k,n,x,y,m,i,nr1,nr2,j,mi,x1,x2;
p a[100005],b[100005];
 
inline bool cmp(p a,p b) {
    return a.x<b.x;
}
 
int main()
{
    ifstream f("licenta.in");
    ofstream g("licenta.out");
    f>>k>>n;
    for (i=1;i<=n;++i) {
            f>>x>>y;
            if (y-x>=k) {
                    ++nr1;
                    a[nr1].x=x;
                    a[nr1].y=y;
            }
    }
 
    f>>m;
     for (i=1;i<=m;++i) {
            f>>x>>y;
            if (y-x>=k) {
                    ++nr2;
                    b[nr2].x=x;
                    b[nr2].y=y;
            }
    }
 
    sort(a+1,a+nr1+1,cmp);
    sort(b+1,b+nr2+1,cmp);
 
   mi=1000000005;
   for (i=1;i<=nr1;++i) {
        for (j=1;j<=nr2;++j) {
            if (b[j].x>a[i].y-k) break;
            x1=max(a[i].x,b[j].x);
            x2=min(a[i].y,b[j].y);
            if (x2-x1>=k &&x1<mi) mi=x1;
        }
   }
 
   g<<mi<<' '<<mi+k;
 
    f.close();
    g.close();
    return 0;
}
