#include <fstream>
#include <cstring>

using namespace std;

char s[100];
int i,n;
bool ok;

int main()
{
    ifstream f("palind.in");
    ofstream g("palind.out");
    f>>s;
    ok=true;
    n=strlen(s);
    for (i=0;i<=n/2;i++) {
        if (s[i]!=s[n-i-1]) ok=false;
        if (ok==false) break;
    }
    if (ok==true) g<<"e palind";
    else
    g<<"nu e palind";
    f.close();
    g.close();
    return 0;
}
