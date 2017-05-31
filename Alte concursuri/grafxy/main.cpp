#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
vector <long int> a[100003];
vector <long int> st;
long int n,m,x,y,c[100005],v[100005],i,k,p,viz[100005],inc,sf,sf1,j,nr,r;
bool ok;

int main()
{


    ifstream f("grafxy.in");
    ofstream g("grafxy.out");
    f>>n>>m;
    for (i=1;i<=m;i++){
        f>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    f>>k;
    for (i=1;i<=k;i++)
        f>>c[i];
    f>>p;
    for (i=1;i<=p;i++) {
        f>>x;
        v[x]=1;
    }

    for (i=1;i<=k;i++)
        {
            for (j=1;j<=n;j++)
            if (viz[j]==1) viz[j]=0;
            st.push_back(c[i]);
            inc=0;sf=0;sf1=0;
            viz[c[i]]=1;
            ok=true;nr=0;
            while (ok==true) {
                nr++;
                for (r=inc;r<=sf;r++)
                for (j=0;j<a[st[r]].size();j++)
                    if (viz[a[st[r]][j]]==0&&ok==true) {sf1++;st.push_back(a[st[r]][j]);viz[a[st[r]][j]]=1; if (v[a[st[r]][j]]==1) {g<<nr<<'\n';ok=false;break;}}
                inc=sf+1;
                sf=sf1;
        }
        st.clear();
        }


    f.close();
    g.close();
    return 0;
}
