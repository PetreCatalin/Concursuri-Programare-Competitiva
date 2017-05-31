#include <fstream>
#include <vector>

using namespace std;

long a[3000005],n,k,i,x;

long partitie(long l,long r)  //al catelea e elementrul a[r] in vector
{
    long p,i,j;
    p=a[r];
    j=l-1;
    for (i=l;i<=r;i++)
        if (a[i]<=p) swap(a[++j],a[i]);
    return j;
}

long divide(long k,long l,long r) //cautam al k-lea element minim
{
    long x;
    x=partitie(l,r);
    if (x==k) return a[k];
    else
    if (x<k) return divide(k,x+1,r);
    else
    return divide(k,l,x-1);

}

int main()
{
    ifstream f("sdo.in");
    ofstream g("sdo.out");
    f>>n>>k;
    for (i=1;i<=n;i++)
        f>>a[i];

    x=divide(k,1,n);
    g<<x;

    f.close();
    g.close();
    return 0;
}
