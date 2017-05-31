// reuniune.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <math.h>
#include <algorithm>

int maxim(int a,int b)
{
    if (a>b) return a;
    else
    return b;
}

int minim(int a,int b)
{
    if (a<b) return a;
    else
    return b;
}

int a,p,x1,x2,x3,x4,z1,z2,z3,z4,t1,t2,t3,t4,ok1,ok2,ok3,c1,c2,c3,c4;


int _tmain(int argc, _TCHAR* argv[])
{
    scanf("%d%d%d%d",&x1,&x2,&x3,&x4);
    scanf("%d%d%d%d",&t1,&t2,&t3,&t4);
    scanf("%d%d%d%d",&z1,&z2,&z3,&z4);

    a=a+abs((x3-x1)*(x4-x2));
    a=a+abs((t3-t1)*(t4-t2));
    a=a+abs((z3-z1)*(z4-z2));

    ok1=1;
    if (t2>=x4 ||x2>=t4) ok1=0;
    if (ok1==1) {
        c1=maxim(x1,t1);
        c2=maxim(x2,t2);
        c3=minim(x3,t3);
        c4=minim(x4,t4);
        a=a-abs((c3-c1)*(c4-c2));
    }

    ok2=1;
    if (t2>=z4 ||z2>=t4) ok2=0;
    if (ok2==1) {
        c1=maxim(z1,t1);
        c2=maxim(z2,t2);
        c3=minim(z3,t3);
        c4=minim(z4,t4);
        a=a-abs((c3-c1)*(c4-c2));
    }

    ok3=1;
    if (x2>=z4 ||x2>=t4) ok3=0;
    if (ok3==1) {
        c1=maxim(z1,x1);
        c2=maxim(z2,x2);
        c3=minim(z3,x3);
        c4=minim(z4,x4);
        a=a-abs((c3-c1)*(c4-c2));
    }

    if (ok1==1 &&ok2==1 &&ok3==1) {
       if (t1>c1) c1=t1;
       if (t2>c2) c2=t2;
       if (t3<c3) c3=t3;
       if (t4<c4) c4=t4;
       a=a+abs((c3-c1)*(c4-c2));
    }

    printf("%d\n",a);
    scanf("%d",&c1);

    return 0;
}
	

