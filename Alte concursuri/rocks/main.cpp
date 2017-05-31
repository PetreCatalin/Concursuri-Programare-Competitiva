#include <fstream>
#include <cmath>
#include <cstring>

using namespace std;

long n,i,nr,putere;
char s1[33000][17],s2[33000][17];

int main()
{
    ifstream f("rocks.in");
    ofstream g("rocks.out");
    f>>n;
    s1[1][0]='0';
    s1[2][0]='X';
    s1[3][0]='0';
    if (n==1) g<<s1[1]<<'\n'<<s1[2]<<'\n'<<s1[3];

    else {

    nr=1;
    while (nr<n) {
        nr++;
        putere=pow(2,n);
        for (i=1;i<=putere;i++) {
            strcpy(s2[i],s1[(i+1)/2]);
            if (i%4==1 ||i%4==0) s2[i][strlen(s2[i])]='0';
                else
                s2[i][strlen(s2[i])]='X';
            }
        for (i=1;i<=putere;i++)
            strcpy(s1[i],s2[i]);
    }

    for (i=1;i<=putere;i++)
        g<<s2[i]<<'\n';
    for (i=1;i<=n;i++)
        g<<'0';
    }

    f.close();
    g.close();
    return 0;
}
