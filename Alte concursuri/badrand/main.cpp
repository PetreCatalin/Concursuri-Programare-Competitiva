#include <fstream>
#include <cmath>

using namespace std;

int nr,viz[10000],n,s,z,x,ok;

int main()
{
    ifstream f("badrand.in");
    ofstream g("badrand.out");
    f>>n;
    ok=1;
    while (ok==1) {
        nr++;
        s=(n/100)%10;
        z=(n/10)%10;
        x=s*10+z;
        x=x*x;
      //  g<<n<<' '<<sqrt(x)<<' '<<x<<'\n';
         if (viz[x]==0) viz[x]=1;
        else
            {
                g<<nr;ok=0;break;
            }
        n=x;
    }

    f.close();
    g.close();
    return 0;
}
