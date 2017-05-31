#include <fstream>

using namespace std;

int a[100],st[100],n,i,k;

int main()
{
       ifstream f("submultimi.in");
       ofstream g("submultimi.out");
       f>>n;
       for (i=1;i<=n;i++)
       a[i]=i;
       k=1;
       st[k]=0;
       while (k>0) {
              while (st[k]<n) { //toate elem sunt mai mici sau egale cu n
                     st[k]++;
                     for (i=1;i<=k;i++) g<<st[i]<<" "; g<<"\n"; //indiferent de cate elemente sunt in stiva le scriem
                     k++;
                     st[k]=st[k-1]; //observam ca toate submultimile sunt crescatoare deci st[k] va fi mai mare ca st[k-1] de ac. ii dam direct valoarea acesteia
              }
              --k; //daca stiva are deja n elemente coboram in stiva fara a modifica ce a fost acolo
       }
       f.close();
       g.close();

    return 0;
}
