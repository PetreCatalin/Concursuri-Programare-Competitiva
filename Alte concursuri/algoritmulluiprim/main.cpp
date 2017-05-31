#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector <pair <long int,long int>  > a[100];
long int n,m,x,y,c,st[100],viz[100],nr,j,s,minim,i,poz;

int main()
{
    ifstream f("prim.in");
    ofstream g("prim.out");
    f>>n>>m;
    for (i=1;i<=m;i++) {
        f>>x>>y>>c;
        a[x].push_back(make_pair(y,c));
        a[y].push_back(make_pair(x,c));
    }

    nr=1;
    st[1]=1;viz[1]=1;
    while (nr<n) {
        nr++;
        minim=10000;
        for (i=1;i<=nr-1;i++)
            for (j=0;j<a[st[i]].size();j++)
            if (viz[a[st[i]][j].first]==0 &&a[st[i]][j].second<minim) {minim=a[st[i]][j].second;poz=a[st[i]][j].first;}
        viz[poz]=1;
        if (minim!=10000)
        s=s+minim;
        st[nr]=poz;
    }

    g<<s;


    f.close();
    g.close();
    return 0;
}
