#include <fstream>
#include <algorithm>

using namespace std;

long long v[30005],i,n,j,t;
long long maxim,nr;
char s[10];

int main()
{
    ifstream f("produs4.in");
    ofstream g("produs4.out");
    for (j=1;j<=720;++j) {
        f>>s;
        nr=0;
        for (i=0;i<5;++i)
            if (s[i]>s[i+1]) ++nr;
        ++v[nr];
    }

    for (i=0;i<=5;++i)
        g<<v[i]<<" ";

    f.close();
    g.close();
    return 0;
}
