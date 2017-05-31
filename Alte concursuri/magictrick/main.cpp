#include <fstream>

using namespace std;

int t,k,i,x,j,v1[20],a[5][5],v2[20],nr;

int main()
{
    ifstream f("input.in");
    ofstream g("output.out");
    f>>t;
    for (k=1;k<=t;++k) {
        f>>x;
        for (i=1;i<=4;++i)
            for (j=1;j<=4;++j)
                f>>a[i][j];
        for (j=1;j<=4;++j)
            ++v1[a[x][j]];

        f>>x;
        for (i=1;i<=4;++i)
            for (j=1;j<=4;++j)
                f>>a[i][j];
        for (j=1;j<=4;++j)
            ++v2[a[x][j]];

        nr=0;
        for (i=1;i<=16;++i)
            if (v1[i]==1 &&v2[i]==1) {++nr;x=i;}

        g<<"Case #"<<k<<": ";
        if (nr==1) g<<x;
        if (nr>1) g<<"Bad magician!";
        if (nr==0) g<<"Volunteer cheated!";
        g<<"\n";

        for (i=1;i<=16;++i) {
            if (v1[i]!=0) v1[i]=0;
            if (v2[i]!=0) v2[i]=0;
        }
    }

    f.close();
    g.close();

    return 0;
}
