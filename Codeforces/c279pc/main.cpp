#include <iostream>
#include <cstring>

using namespace std;

long long A[1000005],v1[1000005],v2[1000005];
long long x,y,nr,ok,i,j,r1,r2,t;
char c[1000005];

long long divide(long long A[],long long X)
/* Intoarce A%X */
{
  long long R=0,i;

  for (i=1;i<=A[0];++i)
    R=(10*R+A[i])%X;
  return R;
}

int main()
{
    cin>>c;
    nr=strlen(c)-1;
        for (i=0;i<=nr;++i)
            A[i+1]=c[i]-'0';

    cin>>x>>y;
    ok=0;
    for (i=1;i<=nr;++i) {
        if (A[1]!=0 &&A[i+1]!=0) {
            t=0;
            for (j=1;j<=i;++j)
                v1[j]=A[j];
                v1[0]=i;
                t=1;
            for (j=i+1;j<=nr+1;++j) {
                v2[t]=A[j];
                ++t;
            }
            v2[t]=0;
            v2[0]=t-1;
        r1=divide(v1,x);
        r2=divide(v2,y);
        if (r1==0 &&r2==0) {
            ok=1;
            cout<<"YES"<<'\n';
            for (j=1;j<=i;++j)
                cout<<v1[j];
            cout<<'\n';
            for (j=1;j<=t-1;++j)
                cout<<v2[j];
            break;
        }
        }
    }

    if (ok==0) cout<<"NO";

    return 0;
}
