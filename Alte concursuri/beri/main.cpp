#include <fstream>

using namespace std;

long long v[1000005],n,k,q,x,y,z,i,val,s;


long long partitie(long long l,long long r)  //al catelea e elementrul v[r] in vector
{
    long long p,i,j;
    p=v[r];
    j=l-1;
    for (i=l;i<=r;i++)
        if (v[i]<=p) swap(v[++j],v[i]);
    return j;
}

long long divide(long long k,long long l,long long r) //cautam pozitia pe care apare al n-k-lea element minim,urmand sa adunam cele mai mari k numere
{
    long x;
    x=partitie(l,r);
    if (x==k) return k;
    else
    if (x<k) return divide(k,x+1,r);
    else
    return divide(k,l,x-1);
}

int main()
{
    ifstream f("beri.in");
    ofstream g("beri.out");
    f>>n>>k;
    f>>q>>x>>y>>z;

    v[1]=q;
    for (i=2;i<=n;++i)
        v[i]=(v[i-1]*x+y)%z+k;

    x=divide(n-k,1,n);

    for (i=x+1;i<=n;++i)
        s=s+v[i];
    s=s-((k-1)*k)/2;
    g<<s;

    f.close();
    g.close();
    return 0;
}
