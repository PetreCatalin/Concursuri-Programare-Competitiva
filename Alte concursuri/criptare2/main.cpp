#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

vector <long> h[20005];
long  n,i,nr,v[28],j,n1,x,vec1[28],ok,k;
char s[30];

int main()
{
    ifstream f("criptare2.in");
    ofstream g("criptare2.out");
    f>>n;
    for (i=1;i<=n;++i) {
        f>>s;
        nr=0;x=0;
        h[i].push_back(strlen(s));
        for (j=0;j<=strlen(s)-1;++j) {
            if (v[s[j]-'a']==0) {
                ++nr;
                v[s[j]-'a']=nr;
            }
                h[i].push_back(v[s[j]-'a']);
        }
           memset(v,0,sizeof(v));
    }

    f>>n1;
    for (i=1;i<=n1;++i) {
        f>>s;
         nr=0;x=0;
        for (j=0;j<=strlen(s)-1;++j) {
            if (v[s[j]-'a']==0) {
                ++nr;
                v[s[j]-'a']=nr;
                vec1[j+1]=nr;
            }
            else
             vec1[j+1]=v[s[j]-'a'];
        }

        memset(v,0,sizeof(v));

        ok=0;
        for (j=1;j<=n;++j) {
            if (h[j][0]==strlen(s)) {
                ok=1;
                for (k=1;k<=strlen(s);++k)
                    if (vec1[k]!=h[j][k]) {ok=0;break;}
            }
        if (ok==1) break;
        }

        if (ok==1) g<<'1'<<'\n';
        else
        g<<'0'<<'\n';
    }

    f.close();
    g.close();
    return 0;
}
