#include <cstring>
#include <fstream>
#include <cstdlib>

using namespace std;

long long  int n,a;
char s[1000];

int main()
{
    ifstream f("baza.in");
    ofstream g("baza.out");
    f>>n;
    ltoa(n,s,2);
    a=atol(s);

    f.close();
    g.close();
    return 0;
}
