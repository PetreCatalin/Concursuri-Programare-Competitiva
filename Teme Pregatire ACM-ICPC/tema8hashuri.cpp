#include <fstream>
#include <unordered_map>

using namespace std;

int main()
{
    long int n,i,op,x;
    unordered_map <int,int> m;

    ifstream f("hashuri.in");
    ofstream g("hashuri.out");
    f>>n;
    for (i=1;i<=n;++i) {
            f>>op>>x;
            if (op==1) ++m[x];
            if (op==2) m.erase(x);
            if (op==3) {
                if (m.find(x)==m.end()) g<<"0\n";
                else
                g<<"1\n";
            }
    }

    f.close();
    g.close();
    return 0;
}
