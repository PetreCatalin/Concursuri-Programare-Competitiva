#include <fstream>
#include <cmath>

using namespace std;

long int v[2000005],i,n,x,s,nr;

int main()
{
    ifstream f("ciur.in");
    ofstream g("ciur.out");
    f>>n;
    x=2;
    while (x<n) {
        x=x+2;
        v[x]=1;
    }
    x=3;
    while (x*x<=n) {
        if (v[x]==0) {
            s=x;
            while (s<n) {
                s=s+x*2;
                v[s]=1;
            }
        }
    x=x+2;
    }

    nr=0;
    for (i=2;i<=n;i++)
    if (v[i]==0) nr++;
    g<<nr;

    f.close();
    g.close();
    return 0;
}

//luam un vector cu toate valorile 0
//il luam pe 2 si punem 1 la toti multiplii lui mai mici ca n;
//luam toate numerele prime <=radical din n si punem 1 la toti multiplii lor impari,la cei pari e deja 1;
//pentru a lua numerele prime nu mai trebuie sa le verificam .trebuie doar ca v[nr] sa fie 0 si asa sigur acel numar e prim;
//sigur e prim fiindca au fost ianainte numere mai mici prin care se gasea sigur un divizor si v[nr] devenea 1;
//numaram cati de 0 au mai ramas in vector de la 2 la n si ala e rezultatul
