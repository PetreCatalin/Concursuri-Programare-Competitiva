#include <fstream>

using namespace std;

long long v[40],s,i,nr,j,aux,x,y,k,n;

int main()
{
    ifstream f("pic.in");
    ofstream g("pic.out");
    f>>n;
    s=0;
    for (i=1;i<=n;i++) {
        f>>x;
        nr=0;
        for (j=1;j<=x;j++) {
            f>>y;
            nr=nr*10+y;
        }
    s=s+nr;
    }
    f>>k;
    for (i=1;i<=k;i++) {
        f>>x;
        nr=0;
        for (j=1;j<=x;j++) {
            f>>y;
            nr=nr*10+y;
        }
    v[i]=nr;
    }

    for (i=1;i<=k-1;i++)
        for (j=i+1;j<=k;j++)
            if (v[i]>v[j]) {
                aux=v[i];
                v[i]=v[j];
                v[j]=aux;
            }
    nr=0;
    x=0;
    i=1;
    while (x<=s) {
        x=x+v[i];
        nr++;
        if (i==k) break;
        i++;
    }
    if (x>s) --nr;
    g<<nr;
    f.close();
    g.close();
    return 0;
}
//numere mari ptr 100 de puncte!!!!!!!!!!!!
