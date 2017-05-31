#include <fstream>
#include <vector>
#include <stack>
#include <bitset>

using namespace std;

int numar,lungime,i;
vector <bool> ciclu;
bool viz[1<<20],ok=false;

int nbit(int & nr,int & pos)
{
    int nou=nr | (1<<(pos-1));
    nou^=(1<<(pos-1));
    return nou;
}

void dfs(int nod)
{
    int c,i,nr;
    stack<int> st;

    st.push(nod);
    while (!st.empty())
    {
        nod=st.top();
        st.pop();
        if (!viz[nod])
        {
            ++lungime;
            viz[nod]=true;
            ciclu.push_back(nod &1);
            c=nbit(nod,numar);
            c<<=1;

            ok=false;
            nr=(1<<numar)-2;
            for (i=0;i<numar-1;++i,nr-=(1<<i))
                if (c==nr)
                {
                    ok=true;
                    break;
                }

            if (!ok)
            {
                st.push(c+1);
                st.push(c);
            }
            else
            {
                st.push(c);
                st.push(c+1);
            }
        }
    }
}

int main()
{
    ifstream f("biti.in");
    ofstream g("biti.out");
    f>>numar;
    lungime=numar-1;
    dfs(0);
    g<<lungime<<"\n";

    for (i=0;i<numar-1;++i)
        g<<0;
    for (i=0;i<ciclu.size();++i)
        g<<ciclu[i];

    f.close();
    g.close();
    return 0;
}
