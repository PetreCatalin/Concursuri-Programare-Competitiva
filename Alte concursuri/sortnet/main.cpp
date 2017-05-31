#include <fstream>
#include <cstring>

using namespace std;

char s[10];
long int i,j,x,nr1,n,m,v1[450],v2[450],a[25],y,suma,ll,k1,k2,aux,b[25];
bool ok;
long long k,r,nrf;

int main()
{
    ifstream f("sortnet.in");
    ofstream g("sortnet.out");
    f>>n>>m;
    nr1=0;
    for (j=1;j<=m*n/2;j++) {
        f>>s;
        x=strlen(s);
        for (i=0;i<=x-1;i++) {
        if (s[i]<='9' &&s[i]>='0'  &&s[i-1]=='<') {
            nr1++;
            v1[nr1]=s[i]-'0';
        }
        if (s[i]<='9' &&s[i]>='0' &&s[i+1]=='>')
            v2[nr1]=s[i]-'0';
        }
    }

    k=1;
    r=2;
    for (i=2;i<=n;i++)
    r=r*2;
    nrf=1;
    x=0;

    while (k<r) {
        k++;
        for (i=n;i>=1;--i) {
            y=a[i];
            if (i==n) { suma=a[i]+1; if (suma==2 ||suma==0) a[i]=0; else a[i]=1;}
            else {
                suma=x+a[i];
                if (suma==2 ||suma==0) a[i]=0;
                else
                a[i]=1;
            }
            x=y;
        }


        for (i=1;i<=n;i++)
        b[i]=a[i];

        ll=1;
        while (ll<=n/2*m) {
            for (i=ll;i<=ll+n/2-1;i++) {
                k1=v1[i];
                k2=v2[i];
            if (b[k1]>b[k2]) {
                aux=b[k1];
                b[k1]=b[k2];
                b[k2]=aux;
            }
            }
            ll=ll+n/2;
        }

        ok=true;
        for (i=1;i<=n-1;i++)
            if (b[i]>b[i+1]) {ok=false;break;}

        if (ok==true) nrf++;
    }

    g<<nrf;

    f.close();
    g.close();
    return 0;
}
