#include <fstream>

using namespace std;

#define maxim 30000
int v[52],t[52][52],w[52][52],*tmin[52],in[52][1005],n,k,mint,mink,i,j,p,m;

struct coada{
    int i;
    int k;
} *c;

int timpminim(int km)
{
    int i,j,p,k,q,u,vf,x;
    for (i=1;i<=n;++i)
        for (j=0;j<=km;++j)
            tmin[i][j]=maxim;

    tmin[1][0]=0;in[1][0]=1;
    x=maxim;vf=0;u=0;
    c[0].i=1;c[0].k=0;

    while (vf<=u) {
            i=c[vf].i;
            k=c[vf++].k;
            if (tmin[i][k]<x)
                for (j=1;j<=n;++j)
                if (t[i][j]<maxim&& k+w[i][j]<=km) {
                        p=tmin[i][k]+t[i][j];
                        q=k+w[i][j];
                        if (v[j]) q=0;
                        if (p<tmin[j][q]) {
                                tmin[j][q]=p;
                                if (j==n &&tmin[j][q]<x)
                                    x=tmin[j][q];
                                if (!in[j][q] &&tmin[j][q]<x) {
                                        in[j][q]=1;
                                        c[++u].i=j;c[u].k=q;
                                }
                        }
                }
                in[i][k]=0;
    }
return x;
}

int main()
{
    ifstream f("lanterna.in");
    ofstream g("lanterna.out");
    f>>n>>k;
    for (i=1;i<=n;++i)
        f>>v[i];

    f>>m;
    for (i=1;i<=n;++i)
        for (j=1;j<=n;++j) {
            t[i][j]=maxim;
            w[i][j]=1006;
        }

    for (p=1;p<=m;++p) {
            f>>i>>j;
            f>>t[i][j]>>w[i][j];
            t[j][i]=t[i][j];
            w[j][i]=w[i][j];
    }

    for (i=0;i<=n;++i)
        tmin[i]=new int [k+1];
    c=new coada[50000];

   int st=1,dr=k-1,mij;
    mint=timpminim(k);
    mink=k;
    while (st<=dr) {
        mij=(st+dr)/2;
        if (timpminim(mij)==mint) {
                mink=mij;
                dr=mij-1;
        }
        else
        st=mij+1;
    }

    g<<mint<<' '<<mink;

    f.close();
    g.close();
    return 0;
}
