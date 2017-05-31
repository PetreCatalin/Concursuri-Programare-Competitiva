#include <fstream>

using namespace std;

int a[100],st[100],i,k,n;
bool ok;

int main()
{
    ifstream f("permutari.in");
    ofstream g("permutari.out");
    f>>n;
    for (i=1;i<=n;i++)
    a[i]=i;
    k=1;
    st[k]=0;
    while (k>0) {
           if (st[k]<n) {st[k]++;
           ok=true;
           for (i=1;i<=k-1;i++) if (st[i]==st[k]) ok=false; //verificam sa nu fie 2 nr in stiva care sa se repete
           if (ok==true) { //daca nu sunt trecem mai departe -la urmatorul nivel.. daca sunt ramanem acolo si ++
           if (k==n) {for (i=1;i<=n;i++) g<<st[i]<<" ";  g<<"\n";} //daca nr de elem  din stiva e egal cu n le scriem
           if (k<n) {
                  k++;//putem trece la niv urmator daca ok=true
                  st[k]=0;
           }
           }
           }
           if (st[k]==n) {st[k]=0;--k;} //daca  deja avem n elemente si ultimul este egal cu maximul-nu mai avem unde sa mergem mai departe => coboram in stiva
    }
    f.close();
    g.close();
    return 0;
}
