#include <fstream>
#include <vector>

using namespace std;

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

vector <int> c1,c2;
int n,m,h,a[1002][1002];
long i,j,nr,rez,x1,x2;

int main()
{
    ifstream f("tsunami.in");
    ofstream g("tsunami.out");
    f>>n>>m>>h;
    for (i=1;i<=n;++i)
        for (j=1;j<=m;++j) {
            f>>a[i][j];
            if (a[i][j]==0) {
            c1.push_back(i);
            c2.push_back(j);
            ++nr;
            }
        }

    for (i=0;i<=n+1;++i) {
        a[i][0]=11;
        a[i][m+1]=11;
    }

    for (i=1;i<=m;++i) {
        a[0][i]=11;
        a[n+1][i]=11;
    }

    for (i=0;i<nr;++i)
        for (j=0;j<=3;++j) {
            x1=c1[i]+dx[j];
            x2=c2[i]+dy[j];
            if (a[x1][x2]<h &&a[x1][x2]!=0) {
                a[x1][x2]=11;
                c1.push_back(x1);
                c2.push_back(x2);
                ++rez; ++nr;
            }
        }

    g<<rez;

    f.close();
    g.close();
    return 0;
}
