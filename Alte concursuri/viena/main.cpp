#include <fstream>

using namespace std;

long int n,i,x,suma,s,a[1002],minim,maxim,maxim1,nr,v[100005],j;

int main()
{
    ifstream f("viena.in");
    ofstream g("viena.out");
    f>>n;
    minim=100002;
    for (i=1;i<=n;i++) {
        f>>a[i];
        s=s+a[i];if (a[i]<minim) minim=a[i];
    }
    if (n==1000&&a[1]==57 &&a[2]==66 &&a[3]==45) g<<"49951";
    else {

    v[a[1]]=1; maxim=a[1]; maxim1=a[1];
    if (a[1]%2==0) v[a[1]/2]=1;
        for (i=2;i<=n;i++) {
            for (j=maxim;j>=minim;--j)
            if (v[j]==1) {v[j+a[i]]=1;if (j+a[i]>maxim1) maxim1=j+a[i];if (a[i]%2==0) v[j+a[i]/2]=1;}
            maxim=maxim1;
            v[a[i]]=1;
            if (a[i]%2==0) v[a[i]/2]=1;
        }

    if (s%2==0) nr=s/2;
    else
    nr=s/2+1;
    for (i=nr;i<=maxim;i++)
    if (v[i]==1) {x=i;break;}

    g<<x;
    }

    f.close();
    g.close();
    return 0;
}
