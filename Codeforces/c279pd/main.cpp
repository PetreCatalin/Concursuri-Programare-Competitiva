#include <iostream>
#include <vector>

using namespace std;

vector <long long> c1,c2,v1,v2;
long long x1,x2,y1,y2,i,inc,sf,sf1,minim,x,arie;

int main()
{
    cin>>x1>>y1;
    cin>>x2>>y2;
    c1.push_back(x1*y1);
    c2.push_back(x2*y2);

    if (x1*y1==x2*y2) cout<<'0';
    else {
    minim=0;
    inc=0;
    sf=0;
    for (i=inc;i<=sf;++i)  {
        sf1=sf;
        v1[c1[i]]=minim;
        if (c1[i]%2==0) {c1.push_back(c1[i]/2);++sf1;}
        if (c1[i]%3==0) {c1.push_back(c1[i]/3);++sf1;}
        inc=sf+1;
        sf=sf1;
        ++minim;
    }

    minim=0;
    inc=0;
    sf=0;
    for (i=inc;i<=sf;++i)  {
        sf1=sf;
        v2[c2[i]]=minim;
        if (c2[i]%2==0) {c2.push_back(c2[i]/2);++sf1;}
        if (c2[i]%3==0) {c2.push_back(c2[i]/3);++sf1;}
        inc=sf+1;
        sf=sf1;
        ++minim;
    }

    minim=2000000000;
    for (i=0;i<min(v1.size(),v2.size());++i)
        if (v1[i]!=0 &&v2[i]!=0) {
            x=min(v1[i],v2[i]);
            if (x<minim) {minim=x;arie=i;}
        }
    if (minim==2000000000) cout<<"-1";
    else
    cout<<minim<<'\n';
    cout<<"1 "<<arie<<'\n';
    cout<<"1 "<<arie;
    }

    return 0;
}
