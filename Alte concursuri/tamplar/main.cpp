#include <fstream>

using namespace std;

long i,l,H[50000];

void Mult(long H[], long X)
/* H <- H*X */
{ long i;
   long T=0;

  for (i=1;i<=H[0];i++)
    { H[i]=H[i]*X+T;
      T=H[i]/10;
      H[i]=H[i]%10;
    }
  while (T) /* Cat timp exista transport */
    { H[++H[0]]=T%10;
      T/=10;
    }
}


int main()
{
    ifstream f("tamplar.in");
    ofstream g("tamplar.out");
    f>>l;
    H[0]=1;H[1]=1;
    for (i=2;i<=l-1;++i)
        Mult(H,i);

    for (i=H[0];i>=1;--i)
        g<<H[i];

    f.close();
    g.close();
    return 0;
}
