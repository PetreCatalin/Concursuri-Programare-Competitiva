#include <fstream>
#include <cstring>

using namespace std;


char s[1000];
long int i;

int main()
{
    ifstream f("razboi.in");
    ofstream g("razboi.out");
    f>>s;
    for (i=strlen(s)-1;i>=0;--i) g<<s[i];




    f.close();
    g.close();
    return 0;
}
