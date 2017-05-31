#include <fstream>
#include <unordered_map>

using namespace std;

#define dd 1024*1024+100

long long n,l,u;
unsigned int v[dd],i;

long long num(int nr) {
    unordered_map<unsigned int,int> stiva;
    long long st=1,sol=0,i;

    for (i=1;i<=n;++i) {
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
    ofstream g("secv5.out");
    f>>n>>l>>u;
    --l;
    for (i=1;i<=n;++i)
        f>>v[i];

    g<<num(u)-num(l);

    f.close();
    g.close();
    return 0;
}
