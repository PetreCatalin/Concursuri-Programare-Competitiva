#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector <pair <long int ,long int >  >a[1003];

long int n,m,x,y,b,c,d,i,minim,numar,viz[1003];

void df(long int k,long int s)
{
    int i;
    if (k==y) {
        if (s<minim) {minim=s;numar=1;}
        else
        if (s==minim) numar++;
        }
        else {
    for (i=0;i<a[k].size();i++)
        if (viz[a[k][i].first]==0) {viz[a[k][i].first]=1; df(a[k][i].first,s+a[k][i].second);}
        }
        viz[k]=0;
}

int main()
{
    ifstream f("numar.in");
    ofstream g("numar.out");
    f>>n>>m>>x>>y;
    for (i=1;i<=m;i++) {
        f>>b>>c>>d;
        a[b].push_back(make_pair(c,d));
        a[c].push_back(make_pair(b,d));
    }

    minim=100*1500+10;numar=0;viz[x]=1;
    df(x,0);

    g<<numar;

    f.close();
    g.close();
    return 0;
}
