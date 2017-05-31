#include <iostream>

using namespace std;

long i,j,k,a[20][20],ok,x,y,nr,t,p1,p2,p3;

int main()
{
    cin>>t;
    for (k=1;k<=t;++k) {
        for (i=1;i<=19;++i)
            for (j=1;j<=19;++j)
                cin>>a[i][j];

        ok=0;p2=25;p3=25;
        for (i=1;i<=19;++i) {
                if(ok==1) break;
        for (j=1;j<=19;++j)
            if (a[i][j]!=0 &&ok==0) {
                x=i;
                y=j;nr=0;
                //
                while (x<=19 &&y<=19&&a[x][y]==a[i][j]) {
                        ++x;
                        ++y;
                        ++nr;
                    }
                if (nr>=5) {ok=1;p1=a[i][j];p2=i;p3=j;break;}
                //
                x=i;
                y=j;nr=0;
                while (x<=19 &&a[x][y]==a[i][j]) {
                        ++x;
                        ++nr;
                    }
                if (nr>=5) {ok=1; p1=a[i][j];p2=i;p3=j;break;}
                //
            }
        }
            if (ok==0) {
             p2=25;p3=25;
            for (i=19;i>=1;--i) {
                    if(ok==1) break;
            for (j=1;j<=19;++j)
            if (a[i][j]!=0 &&ok==0) {
                x=i;
                y=j;nr=0;
                while (y<=19 &&a[x][y]==a[i][j]) {
                        ++y;
                        ++nr;
                    }
                if (nr>=5) {ok=1;p1=a[i][j];p2=i;p3=j;break;}
                //
                 x=i;
                y=j;nr=0;
                while (x>=1 &&y<=19 &&a[x][y]==a[i][j]) {
                        --x;
                        ++y;
                        ++nr;
                    }
                if (nr>=5) {ok=1; p1=a[i][j];p2=i;p3=j;break;}
            }
            }
            }
        if (ok==1) cout<<p1<<'\n'<<p2<<' '<<p3<<'\n';
        if (ok==0) cout<<'0'<<'\n';
    }

    return 0;
}
