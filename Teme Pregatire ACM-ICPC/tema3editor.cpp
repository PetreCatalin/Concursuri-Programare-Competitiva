#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

char s[60005];
vector <int> stiva;
long t,i,j,nr,ultim,ok,x,nr1,nr2,nr3,nr4,q;

int main()
{
    ifstream f("editor.in");
    ofstream g("editor.out");
    f>>t;
    for (i=1;i<=t;++i) {
        f>>s;
        nr=strlen(s)-1;
        if (nr==0) g<<":)"<<'\n';
        else {
            nr1=0;nr2=0;nr3=0;nr4=0;
            for (j=0;j<=nr-1;++j) {
                if (s[j]=='*' && !stiva.empty())
                    stiva.pop_back();
                if (s[j]=='(') stiva.push_back(1);
                if (s[j]=='[') stiva.push_back(3);
                if (s[j]==')') stiva.push_back(2);
                if (s[j]==']') stiva.push_back(4);
            }

            q=stiva.size();
            for (j=0;j<q;++j) {
                if (stiva[j]==1) nr1++;
                if (stiva[j]==2) nr2++;
                if (stiva[j]==3) nr3++;
                if (stiva[j]==4) nr4++;
            }

            if (nr1!=nr2 ||nr3!=nr4)
                g<<":("<<'\n';
            else {
            ok=1;
            j=0;
            x=stiva.size();
            while (j<x-1 &&x>0) {
                ++j;
                if (stiva[j]==2 &&stiva[j-1]==1) {
                    stiva.erase(stiva.begin()+j-1);
                    stiva.erase(stiva.begin()+j-1);
                    x=x-2;
                    j=j-2;
                }
                else
                if (stiva[j]==4 &&stiva[j-1]==3) {
                    stiva.erase(stiva.begin()+j-1);
                    stiva.erase(stiva.begin()+j-1);
                    j=j-2;
                    x=x-2;
                }
            }

            if (stiva.empty()) ok=1;
            else
            ok=0;

            if (ok==1) g<<":)";
            else
            g<<":(";
            g<<'\n';
            }
        if (!stiva.empty()) stiva.erase(stiva.begin(),stiva.end());
        }
    }

    f.close();
    g.close();
    return 0;
}
