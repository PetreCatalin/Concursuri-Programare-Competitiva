#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> v;
vector <int> v1;
vector <pair<int,int> >v2[50];
int i,n,j,x,y,c;

int main()
{
    ifstream f("stl.in");
    ofstream g("stl.out");
    f>>n;
    for (i=1;i<=n;i++)
        v.push_back(i);
        v.pop_back();

    for (i=0;i<v.size();i++)
        g<<v[i]<<' ';

    v1=v;
    if (v1==v) g<<'n';

    f>>x>>y>>c;
    v2[x].push_back(make_pair(y,c));

    v.erase(v.begin()+2);

    g<<v2[x][0].first;
    g<<v2[x][0].second;


    f.close();
    g.close();
    return 0;
}
