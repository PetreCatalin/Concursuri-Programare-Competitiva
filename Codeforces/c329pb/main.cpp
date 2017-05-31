#include <bits/stdc++.h>

using namespace std;

long long n,x1,x2,i,ok,j,x,a,b;


struct punct{
    long long y1,y2;
}v[100002];

inline bool cmp(punct x,punct y)
{
    if (x.y1==y.y1) return x.y2<y.y2;
    return x.y1<y.y1;
}

int main()
{
    cin>>n;
    cin>>x1>>x2;
    for (i=1;i<=n;++i) {
        cin>>a>>b;
        v[i].y1=a*x1+b; //calculam y pe cele doua drepte (x1,x2)
        v[i].y2=a*x2+b;
    }

    sort(v+1,v+n+1,cmp);
    ok=0;

    for (i=2;i<=n;++i)
        if (v[i].y2<v[i-1].y2) {ok=1;break;} //daca am un y2 mai jos decat alt y2 care are y1 mai jos inseamna ca cele 2 dr. se intersecteaza

    if (ok==1) cout<<"YES";
    else
    cout<<"NO";
    return 0;
}
