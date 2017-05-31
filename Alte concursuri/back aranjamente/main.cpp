#include <fstream>

using namespace std;

int a[100],st[100],n,p,i,k;
bool ok;

int main()
{
    ifstream f("aranj.in");
    ofstream g("aranj.out");
    f>>n>>p;
    for (i=1;i<=n;i++)
    a[i]=i;
    k=1;
    st[k]=0;
    while (k>0) {
           if (k<=p && st[k]<n) { //stiva are maxim p elemente si toate sunt <=n
                  st[k]++;
                  ok=true;
                  for (i=1;i<=k-1;i++)
                  if (st[i]==st[k]) {ok=false;break;}  //verificam sa nu se repete
                  if (ok==true) {
                         if (k==p) {for (i=1;i<=k;i++) g<<st[i]<<" "; g<<"\n";} //daca nu se repeta si st are p elem le scriem
                         k++;//daca nu se repeta urcam in stiva ,daca se repeta ramanem acolo pana ok=true;
                         st[k]=0;
                  }
           }
           if (k>p) --k; //daca am depasit p elemente coboram in stiva
           if (st[k]==n) {st[k]=0;--k;} //daca in stiva e un element =n ,fiind deja scris coboram in stiva
    }
    f.close();
    g.close();
    return 0;
}
