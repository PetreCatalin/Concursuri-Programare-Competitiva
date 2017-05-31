#include <cstdio>

using namespace std;

long int n,i,j;
bool ok;

typedef struct {
    long int x;
    long int y;
}nume;

nume a[5003];

int main()
{
    freopen ("triunghi5.in","r",stdin);
    freopen ("triunghi5.out","w",stdout);

    scanf ("%d",&n);
    for (i=1;i<=n;i++)
        scanf ("%d%d",&a[i].x,&a[i].y);

    for (i=1;i<=n;i++) {
        double d=a[i].y;


        long int minim=0;
        long int t=0;
        for (j=1;j<=n;j++) {
        if (a[j].y>minim &&a[j].y<a[i].y&&a[i].x>a[j].x) {minim=a[j].y;t=a[j].x;}
        if (a[j].y==minim &&a[j].x>t &&a[j].x<a[i].x) t=a[j].x;
        }
        ok=false;
        if (minim!=0 &&t!=0) {
            double r;
            r=a[i].x-t;
            if (r<minim/t) {
            ok=true;
            double o=(double) t/minim;r=r+o;
            printf("%0.4f\n",d*r/2);
            }
        }

        if (ok==false) {
        double d=(double) a[i].x*a[i].y/2;
        printf("%0.4f\n",d);
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
