#include <fstream>
#include <cstring>

using namespace std;

char s1[100],s2[100];
int a[30],b[30],i,n;
bool ok;

int main()
{
    ifstream f("anag.in");
    ofstream g("anag.out");
    f>>s1;
    f>>s2;
    n=strlen(s1)-1;
    for (i=0;i<=n;i++)
       a[s1[i]-'a']++;
    n=strlen(s2)-1;
    for (i=0;i<=n;i++)
       b[s2[i]-'a']++;
    ok=true;
    for (i=0;i<=25;i++) {
       if (a[i]!=b[i]) ok=false;
       if (ok==false) break;
    }
    if (ok) g<<"sunt anagrame";
    else g<<"nu sunt anagrame";
    f.close();
    g.close();
    return 0;
}
