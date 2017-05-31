#include <fstream>
#include <vector>

using namespace std;

long rez[100002],vizm[100002],vizn[100002],gr[100002],r,n,m,i,x,y,dif;
vector<pair<long,long> >v[50005];

void ciclue(long nod)
{
  long i,nod1,muchie;
  vizn[nod]=1;

  for (i=0;i<v[nod].size();++i) {
    nod1=v[nod][i].first;
    muchie=v[nod][i].second;
    if (vizm[muchie]==1) continue;

    vizm[muchie]=1;
    ciclue(nod1);
    rez[muchie]=nod1;
  }
}

int main()
{
  ifstream f("fotbal2.in");
  ofstream g("fotbal2.out");
  f>>n>>m;

  for (i=1;i<=m;++i) {
    f>>x>>y;
    v[x].push_back(make_pair(y,i));
    v[y].push_back(make_pair(x,i));
    ++gr[x];
    ++gr[y];
  }

  x=m;
  for (i=1;i<=n;++i)
    if (gr[i]%2==1) {
      dif=2;   //daca nu e eulerian diferenta e 2,altfel e 0
      v[r].push_back(make_pair(i,++x));
      v[i].push_back(make_pair(r,x));
    }

  for (i=1;i<=n;++i)
    if (vizn[i]!=1) ciclue(i);

  g<<dif<<"\n";
  for (i=1;i<=m;++i)
    g<<rez[i]<<"\n";

    f.close();
    g.close();
  }
