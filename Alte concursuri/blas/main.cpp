#include <fstream>

using namespace std;

# define mod 10067

long long a,b,c,n,i,t,x,y,z,nr,aux;

int main()
{
    ifstream f("blas.in");
    ofstream g("blas.out");
    f>>t;
    for (i=1;i<=t;++i) {
            f>>n;
            if (n==1) g<<'1';
            else
            if (n==2) g<<'2';
            else
            if (n==3) g<<'3';
            else
            if (n==4) g<<'6';
            else
            if (n==5) g<<'8';
            else
            if (n==6) g<<"12";
            else {
                a=4;x=2;
                b=5;y=3;
                c=6;z=6;
                nr=6;
                while (nr<n) {
                        ++nr;
                        aux=(b+y)%mod;
                        x=y;
                        y=z;
                        z=aux;
                        aux=(a+c)%mod;
                        a=b;
                        b=c;
                        c=aux;
                }
                g<<(c+z)%mod;
            }

            g<<"\n";
    }

    f.close();
    g.close();
    return 0;
}
