#include <fstream>

using namespace std;

long int minim,maxim,maxim1,i,j,n,v[705],s,a[105],elem;

int main()
{
    ifstream f("cds.in");
    ofstream g("cds.out");
    f>>n;
    minim=800;
    for (i=1;i<=n;i++) {
        f>>a[i];
        if (a[i]<minim) minim=a[i];
        s=s+a[i];
    }

    v[a[1]]=a[1];
    maxim=a[1];maxim1=maxim;
    for (i=2;i<=n;i++) {
        for (j=maxim;j>=minim;--j)
        if (v[j]!=0 &&j+a[i]<=700) {
            v[j+a[i]]=a[i];
            if (j+a[i]>maxim1) maxim1=j+a[i];
        }
        v[a[i]]=a[i];
        if (a[i]>maxim1) maxim1=a[i];
        maxim=maxim1;
    }

    for (i=700;i>=minim;--i)
        if (v[i]!=0) {elem=i;break;}

    if (s-elem>700) g<<"0"<<' '<<"0";
    else
     {
         if (s-elem<elem) g<<s-elem<<' '<<elem;
         else
         g<<elem<<' '<<s-elem;
     }

    f.close();
    g.close();
    return 0;
}
