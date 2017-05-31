#include <fstream>
#include <cstring>

using namespace std;

long t,a,x,i,s,b,viz[103],nr;
char str[100005];

inline void sub(char str[100005])
{
    long i,r;
    nr++;
    r=str[strlen(str)-1]-'0';
    for (i=r;i<=t;i++)
        if (viz[])

}



int main()
{
    ifstream f("ants.in");
    ofstream g("ants.out");
    f>>t>>a>>s>>b;
    for (i=1;i<=a;i++) {
        f>>x;
        viz[x]++;
    }

    for (i=1;i<=t;i++) {
        str[0]='0'+i;
        sub(str);
    }

    g<<nr;

    f.close();
    g.close();
    return 0;
}
