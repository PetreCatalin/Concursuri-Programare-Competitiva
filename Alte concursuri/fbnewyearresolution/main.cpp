#include <fstream>
#include <vector>

using namespace std;

vector <long> c1,c2,c3;

long t,i,j,r,a[22],b[22],c[22],ok,x,y,z,n,nr,nr1;

int main()
{
    ifstream f("input.in");
    ofstream g("output.out");
    f>>t;
    for (r=1;r<=t;++r) {
        f>>x>>y>>z;
        f>>n;
        for (i=1;i<=n;++i)
            f>>a[i]>>b[i]>>c[i];

        nr=0;nr1=0;ok=0;
        for (i=1;i<=n;++i) {
            if (ok==1) break;
            if (a[i]<=x &&b[i]<=y &&c[i]<=z) {
                nr=nr1;
                for (j=0;j<=nr-1;++j) {
                    if (c1[j]==x &&c2[j]==y &&c3[j]==z) {ok=1;break;}
                    if (c1[j]+a[i]<=x &&c2[j]+b[i]<=y &&c3[j]+c[i]<=z) {
                        ++nr1;
                        c1.push_back(c1[j]+a[i]);
                        c2.push_back(c2[j]+b[i]);
                        c3.push_back(c3[j]+c[i]);
                        if (c1[j]+a[i]==x &&c2[j]+b[i]==y &&c3[j]+c[i]==z) {ok=1;break;}
                    }
                }
                ++nr1;
                c1.push_back(a[i]);c2.push_back(b[i]);c3.push_back(c[i]);
                if (c1[nr1-1]==x &&c2[nr1-1]==y &&c3[nr1-1]==z) {ok=1;break;}
            }
        }

        c1.erase(c1.begin(),c1.begin()+nr1);
        c2.erase(c2.begin(),c2.begin()+nr1);
        c3.erase(c3.begin(),c3.begin()+nr1);


        g<<"Case #"<<r<<": ";
        if (ok==1) g<<"yes";
        else
        g<<"no";
        g<<'\n';
    }

    f.close();
    g.close();
    return 0;
}

