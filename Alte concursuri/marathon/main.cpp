#include <fstream>

using namespace std;

typedef struct {
    int ora;
    int min;
    int sec;
}timp;

int n,i,j;
timp aux,a[5005];

int main()
{
    ifstream f("marathon.in");
    ofstream g("marathon.out");
    f>>n;
    for (i=1;i<=n;i++)
        f>>a[i].ora>>a[i].min>>a[i].sec;

    for (i=1;i<=n-1;i++)
        for (j=i+1;j<=n;j++) {
            if (a[i].ora>a[j].ora) {
                aux=a[i];
                a[i]=a[j];
                a[j]=aux;
            }
            else
            if (a[i].ora==a[j].ora &&a[i].min>a[j].min) {
                aux=a[i];
                a[i]=a[j];
                a[j]=aux;
            }
            else
             if (a[i].ora==a[j].ora &&a[i].min==a[j].min &&a[i].sec>a[j].sec) {
                aux=a[i];
                a[i]=a[j];
                a[j]=aux;
            }
        }

    for (i=1;i<=n;i++)
        g<<a[i].ora<<' '<<a[i].min<<' '<<a[i].sec<<'\n';


    f.close();
    g.close();
    return 0;
}
