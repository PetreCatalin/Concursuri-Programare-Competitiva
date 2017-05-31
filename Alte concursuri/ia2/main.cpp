#include <fstream>

using namespace std;
int i,a[5005],v[30];

int main()
{
    ifstream f("ia.in");
    ofstream g("ia.out");
    for (i=1;i<=5000;++i) {
        f>>a[i];
        v[a[i]+10]++;
    }

    for (i=11;i<=20;++i)
        g<<i-10<<' '<<v[i]<<'\n';

   /* g<<"Id,Prediction"<<'\n';
    for (i=1;i<=5000;++i) {
        if (a[i]<1) a[i]=1;
        if (a[i]>10) a[i]=10;
       g<<i<<','<<a[i]<<'\n';
    } */

    f.close();
    g.close();
    return 0;
}
