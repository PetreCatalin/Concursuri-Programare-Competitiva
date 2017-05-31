#include <fstream>

using namespace std;

long int i,j,st1[100],st2[100],a[100],b[100],l[100],t[100],sf,sf1,maxim,n,poz,v[100],numar;
bool ok;

int main()
{
    ifstream f("domino.in");
    ofstream g("domino.out");
    f>>n;
    for (i=1;i<=n;i++)
    f>>a[i]>>b[i];
    st1[1]=a[1];
    st2[1]=b[1];
    st1[2]=b[1];
    st2[2]=a[1];
    l[1]=1;l[2]=1;sf=2;sf1=2;
    maxim=1;

    for (i=2;i<=n;i++) {
        ok=false;
        for (j=sf;j>=1;--j) {
        if (st2[j]==a[i]) {ok=true;sf1++;st1[sf1]=a[i];st2[sf1]=b[i];l[sf1]=1+l[j];t[sf1]=j; if(l[sf1]>maxim) {maxim=l[sf1];poz=sf1;}}
        if (st2[j]==b[i]) {ok=true;sf1++;st1[sf1]=b[i];st2[sf1]=a[i];l[sf1]=1+l[j];t[sf1]=j; if(l[sf1]>maxim) {maxim=l[sf1];poz=sf1;}}
        }
        if (ok==false) {sf1++;st1[sf1]=a[i];st2[sf1]=b[i];sf1++;st1[sf1]=b[i];st2[sf1]=a[i];}
        sf=sf1;
    }

    g<<maxim<<'\n';
    numar=0;
    while (numar<maxim) {
        numar++;
        v[numar]=poz;
        poz=t[poz];
    }

    for (i=numar;i>=1;--i)
    g<<st1[v[i]]<<' '<<st2[v[i]]<<'\n';

    f.close();
    g.close();
    return 0;
}
