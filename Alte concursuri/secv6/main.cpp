#include <fstream>
#include <vector>

using namespace std;

long long n,m,i,x[8195],nr,rez,nr1,nr2,ult,j,lung;
vector <long long> v;

int main()
{
    ifstream f("secv6.in");
    ofstream g("secv6.out");
    f>>n;
    if (n<8192) m=n;
    else
    m=8192;

    for (i=0;i<=m-1;++i)
        f>>x[i];

    for (i=0;i<=n-1;++i) {
        nr=i+(x[i%8192] ^ x[i/8192]);

        if (i==0) v.push_back(nr);
            else {
                if (nr<v.back()) v.push_back(nr);
                else {
                    while (v.back()<=nr) {
                         if (v.back()<nr &&v.size()>1) ++rez;
                         v.pop_back();
                    }
                    v.push_back(nr);
                }
            }
    }

    g<<rez+n-1;

    f.close();
    g.close();
    return 0;
}


