#include <cstdio>
#include <cmath>

using namespace std;

long int n,d,i,x,y,a[16],b[16],j,k,r,inc,sf,sf1,nr,m,p,sb,sff,q,poz,v1[5000],v2[5000];
bool ok,ok1;
char c;

typedef struct {
    int v[16];
    long int t;
}nume;

nume vec[10000];

int main()
{
    freopen ("volei.in","r",stdin);
    freopen ("volei.out","w",stdout);
    scanf("%d%d",&n,&d);
    for (i=1;i<=2*n;i++) {
        scanf("%d%d ",&x,&y);
        scanf(" %c",&c);
        if (c=='B') {
            a[i]=x;
            b[i]=y;
            vec[1].v[i]=1;
        }
        if (c=='F') {
            a[i]=x;
            b[i]=y;
            vec[1].v[i]=2;
        }
    }

    inc=1;sf=1;sf1=1;vec[1].t=0;nr=0;
    ok=true;
    while (ok==true) {
        nr++;
        for (i=inc;i<=sf;i++)
            for (k=1;k<=n*2-1;k++)
                for (j=k+1;j<=n*2;j++) {
                if (vec[i].v[k]==1 &&vec[i].v[j]==2 &&sqrt((a[k]-a[j])*(a[k]-a[j])+(b[k]-b[j])*(b[k]-b[j]))<=d) {sf1++;vec[sf1].v[k]=2;vec[sf1].v[j]=1;vec[sf1].t=i;
                    for (r=1;r<=n*2;r++)
                    if (vec[sf1].v[r]==0) vec[sf1].v[r]=vec[i].v[r];}
                if (vec[i].v[k]==2 &&vec[i].v[j]==1 &&sqrt((a[k]-a[j])*(a[k]-a[j])+(b[k]-b[j])*(b[k]-b[j]))<=d) {sf1++;vec[sf1].v[k]=1;vec[sf1].v[j]=2;
                    vec[sf1].t=i;
                    for (r=1;r<=n*2;r++)
                    if (vec[sf1].v[r]==0) vec[sf1].v[r]=vec[i].v[r];}

                for (m=1;m<=n*2-1;m++)
                    for (p=m+1;p<=n*2;p++)
                    if (vec[sf1].v[m]==vec[sf1].v[p]) {
                        ok1=true;
                        sb=0;
                        sff=0;
                        for (r=1;r<=n*2;r++)
                            if (r!=m &&r!=p) {
                                if (vec[sf1].v[r]==1) {
                                    if (sb==0) sb=(a[r]-a[m])*(b[p]-b[m])-(b[r]-b[m])*(a[p]-a[m]);
                                    if (sff!=0 &&sb*sff>0) {ok1=false;break;}
                                    if (sb!=0) {
                                        q=(a[r]-a[m])*(b[p]-b[m])-(b[r]-b[m])*(a[p]-a[m]);
                                        if (q*sb<0) {ok1=false;break;}
                                        if (sff!=0 &&q*sff>0) {ok1=false;break;}
                                    }
                                }
                                 if (vec[sf1].v[r]==2 &&ok1==true) {
                                    if (sff==0) sff=(a[r]-a[m])*(b[p]-b[m])-(b[r]-b[m])*(a[p]-a[m]);
                                    if (sb!=0 &&sff*sb>0) {ok1=false;break;}
                                    if (sff!=0) {
                                        q=(a[r]-a[m])*(b[p]-b[m])-(b[r]-b[m])*(a[p]-a[m]);
                                        if (q*sff<0) {ok1=false;break;}
                                        if (sb!=0 &&q*sb>0) {ok1=false;break;}
                                    }
                                }
                            }
                                if (ok1==true) {ok=false;poz=sf1;break;}
                    }
                }
                inc=sf+1;
                sf=sf1;
            }

        printf("%d\n",nr);
        nr=0;
        while (poz!=1) {
            nr++;
            k=poz;
            poz=vec[poz].t;
            for (i=1;i<=n*2;i++)  {
                if (vec[k].v[i]!=vec[poz].v[i]&&v1[nr]==0) v1[nr]=i;
                else
                if (vec[k].v[i]!=vec[poz].v[i]&&v1[nr]!=0) v2[nr]=i;
            }
        }

        for (i=nr;i>=1;--i)
        printf("%d %d %d %d\n",a[v1[i]],b[v1[i]],a[v2[i]],b[v2[i]]);

    fclose(stdin);
    fclose(stdout);
    return 0;
}
