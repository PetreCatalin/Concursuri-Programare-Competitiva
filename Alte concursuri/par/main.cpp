#include <fstream>
#include <vector>

using namespace std;

vector <int> stiva;
int nr,n,i;
char c;

int main()
{
    ifstream f("par.in");
    ofstream g("par.out");
    f>>n;
    if (n%2==1) g<<"-1";

    else {
    for (i=1;i<=n;i++) {
        f>>c;
        if (c==')' &&stiva.empty()) {nr++;stiva.push_back(1);}
        else
        if (c=='(') stiva.push_back(1);
        else
            stiva.pop_back();
    }

    nr=nr+stiva.size()/2;
    g<<nr;
    }

    f.close();
    g.close();
    return 0;
}
