#include <fstream>

using namespace std;

long a[100005],b[100005],n,i,nr1,nr2;
int ext[100005],inte[100005];

inline void df1(long x)
{
    long i;
    for (i=1;i<=n-1;i++)
        if (a[i]==x) {nr1++;df1(b[i]);}
}

inline void df2(long x)
{
    long i;
    for (i=1;i<=n-1;i++)
        if (b[i]==x) {nr2++;df2(a[i]);}
}

int main()
{
    ifstream f("chocmilk.in");
    ofstream g("chocmilk.out");
    f>>n;
    for (i=1;i<=n-1;i++) {
        f>>a[i]>>b[i];
        if (ext[a[i]]==0) ext[a[i]]=1;
        if (inte[b[i]]==0) inte[b[i]]=1;
    }

    for (i=1;i<=n;i++) {
        if (ext[i]!=0 &&inte[i]!=0) {
        nr1=0;nr2=0;
        df1(i);
        df2(i);
        if (nr1+nr2==n-1) g<<i<<'\n';
        }
    }

    f.close();
    g.close();
    return 0;
}
