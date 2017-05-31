#include <fstream>

using namespace std;

long int maxim(long int x,long int y)
{
    if (x>y) return x;
    else
    return y;
}

long int c,l,n,m,minim,v[103],vec[103],i,x,y;

int main()
{
    ifstream f("raft.in");
    ofstream g("raft.out");
    f>>c>>l;
    f>>n;
    m=0;
    for (i=1;i<=n;i++) {
        f>>x>>y;
        if (v[x]<y) v[x]=y;
        if (x>m) m=x;
    }

    vec[1]=v[1];
    for (i=2;i<=m;i++) {
        minim=100000;
        if (v[i]+vec[i-1]<minim) minim=v[i]+vec[i-1];
        if (maxim(v[i],v[i-1])+vec[i-2]<minim) minim=maxim(v[i],v[i-1])+vec[i-2];
        if (maxim(v[i],v[i+1])>v[i-1]) l=maxim(v[i],v[i+1]); else l=v[i-1]; vec[i+1]=vec[i-2]+l;
        if (minim<vec[i] ||vec[i]==0) vec[i]=minim;
    }

    g<<vec[m];

    f.close();
    g.close();
    return 0;
}
