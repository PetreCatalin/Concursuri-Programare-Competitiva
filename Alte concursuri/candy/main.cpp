#include <fstream>

using namespace std;

long n,nopt,fav,m,nr[100000],i,ap[40005],vec[55],bomb[100000],maxim,x,j,ok;

int main()
{
    ifstream f("candy.in");
    ofstream g("candy.out");
    f>>n>>nopt>>fav>>m;
    for (i=1;i<=nopt;i++)
        f>>vec[i];
    for (i=1;i<=fav;i++) {
        f>>x;
        ap[x]=1;
    }

    ok=0;
    while (ok==0 &&i>=1) {
    maxim=n;
    nr[n]=1;
    for (i=maxim;i>=1;i=i-1)
        if (nr[i]==1)
        for (j=1;j<=nopt;j++) {
            if (nr[i-vec[j]]==0) nr[i-vec[j]]=1;
            if (bomb[i]+vec[j]>bomb[i-vec[j]]) bomb[i-vec[j]]=bomb[i]+vec[j];
            if (ap[i-vec[j]]==1) {
                nr[i-vec[j]+m]=1;
                if (vec[j]==m) {ok=-1;break;}
                if (bomb[i-vec[j]+m]<bomb[i-vec[j]]) bomb[i-vec[j]+m]=bomb[i-vec[j]];
                if (i-vec[j]+m>maxim) maxim=i-vec[j]+m;
            }
        }
    }

    if (ok==0)
        g<<bomb[0]<<'\n';
       // for (i=n;i>=0;i=i-1)
        //g<<bomb[i]<<' ';

    else g<<ok;

    f.close();
    g.close();
    return 0;
}
