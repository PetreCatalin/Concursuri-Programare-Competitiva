#include <fstream>

using namespace std;

int a[100],k,j,n,st[100],nr,i;

int main()
{
    ifstream f("bprc.in");
    ofstream g("bprc.out");
    f>>nr;
    for (i=1;i<=nr;i++)
    f>>a[i];
    k=1;
    while (k>0) {
           if (st[k]<a[k]) { //daca elem din stiva nu a ajuns la ultimul element din multime
                  st[k]++;
                  if (k==nr) {for (i=1;i<=nr;i++) g<<st[i]<<" "; g<<"\n";} //daca are nr de elem egal cu numarul de multimi scriem
                  if (k!=nr) {k++;st[k]=0;} //daca nu il are trecem mai sus
           }
           if (st[k]>=a[k]) --k; //daca a ajuns deja la ultimul element din multime mergem jos si il luam pe urmatorul element din multimea precedenta
    }
    f.close();
    g.close();
    return 0;
}
