#include <fstream>
#include <cstring>

using namespace std;

long t,i,nr,j,a[15],aux,r,minim,poz,poz1,b[15],maxim,ok;
char s[15];

int main()
{
    ifstream f("input.in");
    ofstream g("output.out");
    f>>t;
    for (r=1;r<=t;++r) {
        f>>s;
        nr=strlen(s);
         for (j=0;j<=nr-1;++j) {
            a[j+1]=s[j]-'0';
            b[j+1]=a[j+1];
        }
//minim
        ok=0;
        minim=10;
        for (i=nr;i>=2;--i)
            if (a[i]<minim &&a[i]!=0) {
                minim=a[i];
                poz=i;
            }
        if (minim<a[1]) {
            a[poz]=a[1];
            a[1]=minim;
            ok=1;
        }

        if (ok==0)
        for (i=2;i<=nr-1;++i) {
            minim=10;
            if (ok==1) break;
            for (j=nr;j>=i+1;--j)
                if (a[j]<minim) {
                    minim=a[j];
                    poz=j;
                }
            if (minim<a[i]) {
                a[poz]=a[i];
                a[i]=minim;
                ok=1;
                break;
            }
        }

        //maxim;
        ok=0;
        for (i=1;i<=nr-1;++i) {
            maxim=-1;
            if (ok==1) break;
            for (j=nr;j>=i+1;--j)
                if (b[j]>maxim) {
                    maxim=b[j];
                    poz=j;
                }
            if (maxim>b[i]) {
                b[poz]=b[i];
                b[i]=maxim;
                ok=1;
                break;
            }
        }

        g<<"Case #"<<r<<": ";
        for (i=1;i<=nr;++i)
            g<<a[i];
        g<<' ';
        for (i=1;i<=nr;++i)
            g<<b[i];
        g<<"\n";
    }

    f.close();
    g.close();
    return 0;
}
