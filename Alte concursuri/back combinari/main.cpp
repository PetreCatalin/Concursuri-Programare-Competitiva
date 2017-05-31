#include <fstream>

using namespace std;

int a[100],st[100],n,m,i,k;
bool ok;

int main()
{
    ifstream f("bcom.in");
    ofstream g("bcom.out");
    f>>n>>m;
    for (i=1;i<=n;i++)
    a[i]=i;
    k=1;
    st[k]=0;
    while (k>0) {
           if (st[k]<n) {
                  st[k]++;
                  ok=true; for (i=1;i<=k-1;i++) if (st[i]==st[k]) ok=false; //verificam sa nu fie 2 elemente egale
                             if (ok==true && k==m) {for(i=1;i<=k;i++) g<<st[i]<<" "; g<<"\n";}//daca nu sunt le scriem
                  if (ok==true)   //daca nu sunt egale putem urca in stiva ..daca sunt egale ramanem pe ac. poz pana nu mai sunt
                  if (k<m) {k++;st[k]=st[k-1];} //combinarile sunt strict crescatoare,asa ca ii dam direct valoarea celui dinaintea lui
          }
          if (st[k]==n) --k; //lasam asa st[k] ptr a fi comb. strict crescatoare
    }
    f.close();
    g.close();
    return 0;
}
