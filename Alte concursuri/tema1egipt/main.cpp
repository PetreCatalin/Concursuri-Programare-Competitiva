#include <bits/stdc++.h>

using namespace std;

long n,i,v[10005],nr[4],x1,x2,aux,rez;
vector <int> a,b;

int main()
{
    ifstream f("egipt.in");
    ofstream g("egipt.out");
    f>>n;
    for (i=1;i<=n;++i) {
        f>>v[i];
        ++nr[v[i]];
    }
    nr[2]+=nr[1];
    nr[3]+=nr[2];

  //  g<<nr[1]<<' '<<nr[2]<<' '<<nr[3];
    x2=nr[1]+1;
    for (x1=1;x1<=nr[1];++x1)
            if (v[x1]==2) {
                    while (v[x2]!=1 &&x2<n) ++x2;
                    aux=v[x1];
                    v[x1]=v[x2];
                    v[x2]=aux;
                    ++rez;
                    a.push_back(x1); b.push_back(x2);
                    ++x2;
            }

    for (x1=1;x1<=nr[1];++x1)
            if (v[x1]==3) {
                    while (v[x2]!=1 &&x2<n) ++x2;
                    aux=v[x1];
                    v[x1]=v[x2];
                    v[x2]=aux;
                    ++rez;
                    a.push_back(x1); b.push_back(x2);
                    ++x2;
            }

    for (i=nr[1]+1;i<=nr[2];++i)
        if (v[i]==3) {a.push_back(i);++rez;}
    for (i=nr[2]+1;i<=nr[3];++i)
        if (v[i]==2) b.push_back(i);

    g<<rez<<'\n';
    for (i=1;i<=rez;++i)
        g<<a[i-1]<<' '<<b[i-1]<<'\n';


    f.close();
    g.close();
    return 0;
}
