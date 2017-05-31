#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

char s[100005];
vector <int> stiva;
vector <int>::iterator it;
int v[100005];
long m,x,i,ultim,nr;

int main()
{
    ifstream f("parantezare.in");
    ofstream g("parantezare.out");
    f>>s;
    nr=strlen(s)-1;
    for (i=0;i<=nr;++i) {
        if (s[i]=='(') stiva.push_back(i);
        if (s[i]==')') {
            ultim=stiva.back();
            v[ultim]=i;
            stiva.pop_back();
        }
    }

    f>>m;
    for (i=1;i<=m;i++) {
        f>>x;
        g<<v[x]<<' ';
    }

    f.close();
    g.close();
    return 0;
}

