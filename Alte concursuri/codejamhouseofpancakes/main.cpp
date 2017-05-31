#include <cstdio>

using namespace std;

long t,k,i,x,maxim,nr,d,minim,v[12],timp[12],m1;


int main()
{
    freopen ("intrare.in","r",stdin);
    freopen ("iesire.out","w",stdout);
    scanf("%d",&t);
    for (k=1;k<=t;++k) {
            scanf("%d",&d);
            maxim=0;
            for (i=1;i<=d;++i) {
                    scanf("%d",&x);
                    ++v[x];
            }
                for (i=1;i<=3;++i) if (v[i]!=0) timp[i]=i;

                            if (v[4]==1) {timp[4]=2; maxim+=1;}
                            if (v[4]>1) timp[4]=4;
                            if (v[5]==1) {timp[5]=3; maxim+=1;}
                            if (v[5]>1) timp[5]=5;
                            if (v[6]>=1 &&v[6]<=2) {timp[6]=3;maxim+=v[6];}
                            if (v[6]>2) timp[6]=6;
                            if (v[7]>=1 &&v[7]<=2) {timp[7]=4;maxim+=v[7];}
                            if (v[7]>2) timp[7]=7;
                            if (v[8]>=1 &&v[8]<=3) {timp[8]=4;maxim+=v[8];}
                            if (v[8]>3) timp[8]=8;
                            if (v[9]==1) {timp[9]=3;maxim+=1;}
                            if (v[9]>=2 &&v[9]<=3) {timp[9]=2;maxim+=v[9];}
                            if (v[9]>3) timp[9]=9;

            m1=0;
            for (i=1;i<=9;++i) if (timp[i]>m1) m1=timp[i];

             for (i=1;i<=9;++i) {if (v[i]!=0) v[i]=0;if (timp[i]!=0) timp[i]=0;}

            printf("Case #%d: %d\n",k,m1+maxim);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
