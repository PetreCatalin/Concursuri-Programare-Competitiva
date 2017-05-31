#include <fstream>

using namespace std;

long long x,c;
int i,t;

int main()
{
    ifstream f("tt.in");
    ofstream g("tt.out");
    f>>t;
    for (i=1;i<=t;i++) {
        f>>x;
        c=0;
        while (x>0) {
            c=c*10+x%10;
            x=x/10;
        }
        g<<c<<'\n';
    }

    f.close();
    g.close();

    return 0;
}
