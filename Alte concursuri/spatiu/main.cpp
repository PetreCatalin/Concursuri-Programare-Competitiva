#include <fstream>

using namespace std;

long long n,t,i,lungime,latime,j,rez;
char s[100005];

int main()
{
    ifstream f("spatiu.in");
    ofstream g("spatiu.out");
    f>>t;
    for (i=1;i<=t;++i) {
            f>>n;
            f>>s;
            lungime=1;
            latime=1;
            for (j=0;j<n;++j) {
                if (s[j]=='1' || s[j]=='2') ++lungime;
                if (s[j]=='3' || s[j]=='4') ++latime;
                if (s[j]=='5') {
                        ++latime;
                        ++lungime;
                }
            }
            rez=lungime*latime;
            g<<rez<<"\n";
    }

    f.close();
    g.close();
    return 0;
}
