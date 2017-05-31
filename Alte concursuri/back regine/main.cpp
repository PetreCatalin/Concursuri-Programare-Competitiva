#include <fstream>
#include <cmath>

using namespace std;

double l[100],c[100],x,y;
int i,j,n;
bool ok;

int main()
{
       ifstream f("breg.in");
       ofstream g("breg.out");
       f>>n;
       for (i=1;i<=n;i++)
       f>>l[i]>>c[i];
       //verificam daca reginele nu sunt pe ac. linie sau pe ac. coloana
       ok=true;
       for (i=1;i<=n-1;i++)
              for (j=i+1;j<=n;j++){
              if (l[i]==l[j]) ok=false;
              if (c[i]==c[j]) ok=false;
              if (ok==false) break;
              }
       //verificam daca nu sunt pe ac. diagonala
       //ca sa nu fie pe ac. diagonala trebuie ca modulul diferentei coloanelor sa fie diferit de modulul diferentei liniilor a oricaror 2 regine
       if (ok==true) {
              for (i=1;i<=n-1;i++)
                     for (j=i+1;j<=n;j++) {
                     x=abs(l[i]-l[j]);y=abs(c[i]-c[j]);
                     if (x==y) ok=false;
                     if (ok==false) break;
                     }
       }
       if (ok==false) g<<"se pot lua una pe alta";
       else
       g<<"nu se pot lua una pe alta";
       f.close();
       g.close();
    return 0;
}
