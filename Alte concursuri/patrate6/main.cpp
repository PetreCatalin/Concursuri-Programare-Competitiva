#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

inline bool cmp(long long x,long long y)
{
    return x>y;
}

vector <long long> st;
long long v[100005],i,n,nr,j;

int main()
{
    ifstream f("patrate6.in");
    ofstream g("patrate6.out");
    f>>n;
    for (i=1;i<=n;++i)
        f>>v[i];

    sort(v+1,v+n+1,cmp);

    for (i=1;i<=4;++i)
        st.push_back(-1);
    for (i=1;i<=n;++i) {
        st.push_back(v[i]);
        if (st.size()>=4)
            while (st[st.size()-1]==st[st.size()-4]) {
                nr=st[st.size()-1];
                for (j=1;j<=4;++j)
                    st.pop_back();
                st.push_back(nr+1);
            }
    }

    if (st.size()==5) g<<st[4];
    else
    g<<st[4]+1;

    f.close();
    g.close();
    return 0;
}
