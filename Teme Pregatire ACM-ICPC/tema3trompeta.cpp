#include <fstream>
#include <vector>

using namespace std;

char stiva[1000005];
long n,m,i,j,x,t;
char c;

int main()
{
    ifstream f("trompeta.in");
    ofstream g("trompeta.out");
    f>>n>>m;
    t=0;
    for (i=1;i<=n;++i) {
        f>>c;
        if (i==1) stiva[0]=c;
        else {
            if (t+(n-i+2)>=m) {
                x=t;
                while (stiva[x]<c &&x>=0 &&t+(n-i+1)>=m) {stiva[x]='\0';--x;--t;}
                ++t;
                stiva[t]=c;
            }
            else
            if (t<m) {++t;stiva[t]=c;}
        }
    }

    g<<stiva;

    f.close();
    g.close();
    return 0;
}
