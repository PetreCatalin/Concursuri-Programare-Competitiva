#include <iostream>
#include <cstring>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

char s1[12],s2[12];
int i,m,p,p1,m1,rez1,rez2,nr,s,val;
long v1,v2;
double x;

int main()
{
    cin>>s1;
    cin>>s2;
    for (i=0;i<=strlen(s1)-1;i++) {
        if (s1[i]=='+') p++;
        else
        m++;
    }
    for (i=0;i<=strlen(s2)-1;i++) {
        if (s2[i]=='+') p1++;
        else
        if (s2[i]=='-') m1++;
        if (s2[i]=='?') nr++;
    }

    rez1=p-m;
    rez2=p1-m1;
    if (rez1==rez2 &&nr==0) {
            x=1;
            std::cout<<std::setprecision(12)<<x;
        }
        else
    if (rez1==rez2 &&nr%2==1) {
            x=0;
            std::cout<<std::setprecision(12)<<x;
        }
    else
    if (abs(rez1-rez2)>nr) {x=0;std::cout<<std::setprecision(12)<<x;}
    else
        {
             rez1=p-p1;
             if (rez1<0) rez1=rez1*(-1);
             val=pow(2,nr);
             v1=1;
             for (i=nr-rez1+1;i<=nr;i++)
                v1=v1*i;
                v2=1;
                for (i=2;i<=rez1;i++)
                v2=v2*i;
                v1=v1/v2;
            x=(double) v1/val;
            std::cout<<std::setprecision(12)<<x;
        }

    return 0;
}
