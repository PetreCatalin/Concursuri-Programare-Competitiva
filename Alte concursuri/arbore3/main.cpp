#include <fstream>
#include <vector>

using namespace std;

vector <pair <int,int> > m[1000005];
vector<int> st;
int i,n,y,nr,t,s,x,rez;

inline void df( int x,int nr)
{
    long i,ok,j;
    for (i=0;i<m[x].size();++i) {
        if (st.size()>0) {
            nr=st[st.size()-1]+m[x][i].second;
            st.push_back(nr);
            ok=0;
            for (j=0;j<=st.size()-1;++j)
                if (st[j]==nr-s) {ok=1;break;}
            if (ok==1) ++rez;
            df(m[x][i].first,nr);
        }
    }
    if (st.size()>0)
        st.pop_back();
}

int main()
{
   ifstream f("arbore3.in");
   ofstream g("arbore3.out");
    f>>n>>s;
    for (i=1;i<=n;++i) {
        f>>x>>y;
        m[x].push_back(make_pair(i,y));
    }

    st.push_back(0);
    df(0,0);
    g<<rez;

    f.close();
    g.close();
    return 0;
}
