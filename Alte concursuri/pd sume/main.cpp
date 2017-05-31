#include <fstream>

using namespace std;

int a[100],sume[1000],ind[1000],i,n,s,x,j,poz,maxim,nr;

int main()
{
    ifstream f("pds.in");
    ofstream g("pds.out");
    f>>s>>n;
    maxim=0;
    for (i=1;i<=n;i++) {
        f>>a[i];
        if (a[i]>maxim) maxim=a[i];
        sume[a[i]]=1;
        ind[a[i]]=a[i];
    }
    poz=0;
    nr=maxim;
    while (sume[s]==0) {
        poz++;
        for (i=1;i<=maxim;i++) {
        if (sume[i]==poz)
            for (j=1;j<=n;j++) {
                x=i+a[j];
                if (sume[x]==0) {
                    sume[x]=poz+1;
                    ind[x]=a[j];
                }
                if (x>nr) nr=x;
            }
        }
        maxim=nr;
    }
    g<<sume[s]<<'\n';
    while (s>0) {
        g<<ind[s]<<' ';
        s=s-ind[s];
    }
    f.close();
    g.close();
    return 0;
}

//facem 2 vectori ..unul in care punem nr de numere de care am avut nevoie pentru a forma acel numar iar altul
//ptr a scrie ultimul numar care a fost adunat ptr  a ajunge la el ptr a reconstitui suma...
//dam la nr din vecotrul a val 1..le cautam pe cele cu 1 le insumam tot cu ele si scriem 2.....
//dupa le cautam pe cele cu 2,3,4 etc..pe rand si la insumam tot cu elem initiale din vectorul a
//pana cand ajungem sa face suma . ptr a recunstitiu elementele scadeam din suma succesiv ce am adunat
//si am pastrat in vectorul ind
