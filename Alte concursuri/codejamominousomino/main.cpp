#include <cstdio>

using namespace std;

int t,k,x,r,c;

int main()
{
    freopen ("intrare.in","r",stdin);
    freopen ("iesire.out","w",stdout);
    scanf("%d",&t);
    for (k=1;k<=t;++k) {
            scanf("%d%d%d",&x,&r,&c);
            printf("Case #%d: ",k);
            if (x==1) printf("GABRIEL");
            if (x==2) {
                    if ((r*c)%2==0) printf("GABRIEL");
                    else
                    printf("RICHARD");
            }
            if (x==3) {
                    if (r==1 ||c==1) printf("RICHARD");
                    else
                    if (r==2 &&c==2) printf("RICHARD");
                    else
                    if (r*c==6) printf("GABRIEL");
                    else
                    if (r*c==8) printf("RICHARD");
                    else
                    if (r*c==9) printf("GABRIEL");
                    else
                    if (r*c==12) printf("GABRIEL");
                    else
                    if (r*c==16) printf("RICHARD");
            }
            if (x==4) {
                    if ((x*c)%2==1) printf("RICHARD");
                    else {
                         if (r==1 ||c==1) printf("RICHARD");
                        else
                        if (r==2 &&c==2) printf("RICHARD");
                        else
                        if (r*c==6) printf("RICHARD");
                        else
                        if (r*c==8) printf("RICHARD");
                        else
                        if (r*c==9) printf("RICHARD");
                        else
                        if (r*c==12) printf("GABRIEL");
                        else
                        if (r*c==16) printf("GABRIEL");
                    }
            }
            printf("\n");
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
