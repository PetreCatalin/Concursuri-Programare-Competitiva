#include <fstream>

using namespace std;

int n,i,t,nr1,nr0,j;
char x;

int main()
{
    ifstream f("harddp.in");
    ofstream g("harddp.out");
    f>>t;
    for (i=1;i<=t;++i) {
            f>>n;
            nr1=0;
            nr0=0;
            for (j=1;j<=n;++j) {
                f>>x;
                if (x=='0') ++nr0;
                else
                ++nr1;
            }

            if (nr0<nr1)
                for (j=1;j<=n;++j)
                    g<<'0';
            else
                for (j=1;j<=n;++j)
                    g<<'1';
            g<<'\n';
    }

    f.close();
    g.close();
    return 0;
}
