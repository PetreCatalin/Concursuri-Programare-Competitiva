#include <fstream>

using namespace std;

long int i,j,n,k,x,lipsa[100],deter[100],v[100],h;

int main()
{
    ifstream f("pod.in");
    ofstream g("pod.out");
    f>>n;
    f>>k;
    for (i=1;i<=k;i++) {
        f>>x;
        lipsa[x]=1;
    }
    f>>h;
    for (i=1;i<=h;i++) {
        f>>x;
        deter[x]=1;
    }


    if (lipsa[1]==0) v[1]=1;
    if (lipsa[2]==0 &&deter[2]==0) v[2]=1;
    if (lipsa[3]==0 &&deter[3]==0) v[3]=1;


    for (i=1;i<=n;i++) {
        if (deter[i]==0 &&lipsa[i]==0) {
        if (lipsa[i+1]==0) v[i+1]=v[i+1]+v[i];
        if (lipsa[i+2]==0 &&deter[i+2]==0) v[i+2]=v[i+2]+v[i];
        if (lipsa[i+3]==0 &&deter[i+3]==0) v[i+3]=v[i+3]+v[i];
        }
        if (deter[i]==1)
            if (lipsa[i+1]==0) v[i+1]=v[i+1]+v[i];
    }

    if (v[n]==0) g<<"-1";
    else
    g<<v[n];

    f.close();
    g.close();
    return 0;
}
