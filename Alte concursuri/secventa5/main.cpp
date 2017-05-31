#include <fstream>
#include <unordered_map>

using namespace std;

unsigned long n,l,u,i,v[1065000];

long long Count(unsigned long nr) {
    unordered_map<unsigned long, long> stiva;
    int st=1;
    long long sol=0;
    for (unsigned long i=1;i<=n;++i) {
        ++stiva[v[i]];
        while (stiva.size()>nr) {
            --stiva[v[st]];
            if (stiva[v[st]]==0)
                stiva.erase(v[st]);
            ++st;
        }
        sol+=i-st+1;
    }
    return sol;
}

int main()
{
    ifstream f("secv5.in");
   // freopen ("secv5.out","w",stdout);
   ofstream g("secv5.out");
    f>>n>>l>>u;
    for (i=1;i<=n;i++)
        f>>v[i];

   // printf("%Ld",Count(u)-Count(l-1));
   g<<Count(u)-Count(l-1);
  //  fclose(stdin);
  //  fclose(stdout);
  f.close();
  g.close();
    return 0;
}
