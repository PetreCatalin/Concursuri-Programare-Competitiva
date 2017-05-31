#include <iostream>
#include <cstring>

using namespace std;

long n,i,x,y,j,v1,v2,nr1,nr2,nrx;
char s1[105],s2[105];

struct st{
    char s[105];
    int nr;
    int sc;
} v[10];

st aux;

int main()
{
        cin>>v[1].s;
        cin>>v[2].s;
        cin>>x>>y;
        if (x>y) v[1].nr=3;
        if (x<y) v[2].nr=3;
        if (x==y) {v[1].nr=1;v[2].nr=1;}
        v[1].sc=x;
        v[2].sc=y;

        cin>>v[3].s;
        cin>>v[4].s;
        cin>>x>>y;
        if (x>y) v[3].nr=3;
        if (x<y) v[4].nr=3;
        if (x==y) {v[3].nr=1;v[4].nr=1;}
        v[3].sc=x;
        v[4].sc=y;

        for (i=1;i<=4;++i) {
            cin>>s1;
            cin>>s2;
            cin>>x>>y;
            for (j=1;j<=4;++j) {
                nr1=strcmp(v[j].s,s1);
                nr2=strcmp(v[j].s,s2);
                if (nr1==0) v1=j;
                if (nr2==0) v2=j;
            }

            if (x>y) v[v1].nr+=3;
            if (x<y) v[v2].nr+=3;
            if (x==y) {v[v1].nr+=1;v[v2].nr+=1;}
            v[v1].sc+=x;
            v[v2].sc+=y;
        }

        for (i=1;i<=3;++i)
            for (j=i+1;j<=4;++j) {
                if (v[i].nr<v[j].nr) {
                    aux=v[i];
                    v[i]=v[j];
                    v[j]=aux;
                }
                else
                    if (v[i].nr==v[j].nr &&v[i].sc<v[j].sc) {
                        aux=v[i];
                        v[i]=v[j];
                        v[j]=aux;
                    }
                else
                    if (v[i].nr==v[j].nr &&v[i].sc==v[j].sc) {
                        nrx=strcmp(v[i].s,v[j].s);
                        if (nrx>0) {
                            aux=v[i];
                        v[i]=v[j];
                        v[j]=aux;
                        }
                    }
            }

            for (i=1;i<=4;++i)
                cout<<v[i].s<<'\n';

    return 0;
}
