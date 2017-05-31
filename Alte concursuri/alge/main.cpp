#include <fstream>

using namespace std;

const int dx[]={0,0,0,0,1,-1};
const int dy[]={0,1,0,-1,0,0};
const int dz[]={1,0,-1,0,0,0};

long int n,k,x,y,z,l,j,i,r,t,a[38][38][38],st1[45000],st2[45000],inc,sf,sf1,nr,st3[45000],rad[45000],poz,v1[45000],v2[45000],v3[45000],numar;
bool ok;

int main()
{
    ifstream f("alge.in");
    ofstream g("alge.out");
    f>>n>>k;
    for (i=1;i<=k;i++) {
        f>>x>>y>>z>>l;
        for (j=x;j<=x+l-1;j++)
        for (r=y;r<=y+l-1;r++)
        for (t=z;t<=z+l-1;t++)
        a[j][r][t]=1;
    }

    st1[1]=1;st2[1]=1;st3[1]=1;inc=1;sf=1;sf1=1;a[1][1][1]=1;
    ok=true;
    nr=1;
    while (ok==true) {
        nr++;
        for (i=inc;i<=sf;i++) {
            for (j=0;j<6;j++) {
            x=st1[i]+dx[j];
            y=st2[i]+dy[j];
            z=st3[i]+dz[j];
            if (a[x][y][z]==0 &&x>=1 &&x<=n &&y>=1&&y<=n&&z>=1&&z<=n) {
                sf1++;st1[sf1]=x;st2[sf1]=y;st3[sf1]=z;a[x][y][z]=1;rad[sf1]=i;
                 if (x==n &&y==n &&z==n) {ok=false;g<<nr<<'\n';poz=sf1;break;}
            }
            }
        }
        inc=sf+1;
        sf=sf1;
    }

    numar=0;
    while (numar<nr) {
        numar++;
        v1[numar]=st1[poz];
        v2[numar]=st2[poz];
        v3[numar]=st3[poz];
        poz=rad[poz];
    }

    for (i=numar;i>=1;--i)
        g<<v1[i]<<' '<<v2[i]<<' '<<v3[i]<<'\n';

    f.close();
    g.close();
    return 0;
}
