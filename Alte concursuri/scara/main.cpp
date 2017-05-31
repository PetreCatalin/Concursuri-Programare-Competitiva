#include <fstream>

using namespace std;

long int i,k,j,n,x,y,apa[125],ener[125],cost[125],lmin[125];

int main()
{
    ifstream f("scara2.in");
    ofstream g("scara2.out");
    f>>n;
    f>>k;
    for (i=1;i<=k;i++) {
        f>>x>>y;
        apa[x]=y;
    }
    f>>k;
    for (i=1;i<=k;i++) {
        f>>x>>y;
        ener[x]=y;
    }

    for (i=1;i<=n;i++)
    lmin[i]=i;

    for (i=1;i<=n;i++) {
        if (lmin[i+1]>lmin[i]+1) {lmin[i+1]=lmin[i]+1;cost[i+1]=cost[i];}
        else
        if (lmin[i+1]==lmin[i]+1 &&cost[i+1]>cost[i]) cost[i+1]=cost[i];
        if (apa[i]!=0) {
            for (j=i+1;j<=i+apa[i];j++) {
                if (lmin[j]>lmin[i]+1) {lmin[j]=lmin[i]+1;cost[j]=cost[i];}
                else
                if (lmin[j]==lmin[i]+1 &&cost[j]>cost[i]) cost[j]=cost[i];
                }
        }
        if (ener[i]!=0) {
             for (j=i+1;j<=i+ener[i]*2;j++) {
                if (lmin[j]>lmin[i]+1) {lmin[j]=lmin[i]+1;cost[j]=cost[i]+ener[i];}
                else
                if (lmin[j]==lmin[i]+1 &&cost[j]>cost[i]+ener[i]) cost[j]=cost[i]+ener[i];
             }
        }
    }

    g<<lmin[n]<<' '<<cost[n];

    f.close();
    g.close();
    return 0;
}
