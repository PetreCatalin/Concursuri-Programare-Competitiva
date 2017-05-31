/*#include <iostream>

using namespace std;

double alfa;

struct p{
int x,y,z;
}a,b,c;

bool verif(p a,p b)
{
    if (a.x==b.x &&a.y==b.y &&a.z==b.z) return true;
    else
    return false;
}

void colin()
{
    if (verif(a,b)==true ||verif(b,c)==true ||verif(a,c)==true) {
            cout<<"Punctele sunt coliniare\n";
            if (verif(a,b)==true) cout<<"A=1*B+0*C\n";
            else
            if (verif(b,c)==true) cout<<"B=0*A+1*C\n";
            else
            if (verif(a,c)==true) cout<<"A=0*B+1*C\n";
    }

    else {
        bool ok=false;
        double r1,r2,r3,r4,r5,r6;
        r1=b.x-c.x; r2=b.y-c.y; r3=b.z-c.z; r4=a.x-c.x; r5=a.y-c.y; r6=a.z-c.z;

            if (r1==0 && r4==0)
                    if (r2/r5==r3/r6) {
                    alfa=r3/r6;
                    ok=true;cout<<"Punctele sunt coliniare\n";
                    cout<<"B ="<<alfa<<"*A+"<<1-alfa<<"*C";
                    }
#include <iostream>

using namespace std;

double alfa;

struct p{
int x,y,z;
}a,b,c;

bool verif(p a,p b)
{
    if (a.x==b.x &&a.y==b.y &&a.z==b.z) return true;
    else
    return false;
}

void colin()
{
    if (verif(a,b)==true ||verif(b,c)==true ||verif(a,c)==true) {
            cout<<"Punctele sunt coliniare\n";
            if (verif(a,b)==true) cout<<"A=1*B+0*C\n";
            else
            if (verif(b,c)==true) cout<<"B=0*A+1*C\n";
            else
            if (verif(a,c)==true) cout<<"A=0*B+1*C\n";
    }

    else {
        bool ok=false;
        double r1,r2,r3,r4,r5,r6;
        r1=b.x-c.x; r2=b.y-c.y; r3=b.z-c.z; r4=a.x-c.x; r5=a.y-c.y; r6=a.z-c.z;

            if (r1==0 && r4==0)
                    if (r2/r5==r3/r6) {
                    alfa=r3/r6;
                    ok=true;cout<<"Punctele sunt coliniare\n";
                    cout<<"B ="<<alfa<<"*A+"<<1-alfa<<"*C";
                    }
            if (r2==0 &&r5==0)
                    if (r1/r4==r3/r6) {
                    alfa=r1/r4;
                    ok=true;cout<<"Punctele sunt coliniare\n";
                    cout<<"B ="<<alfa<<"*A+"<<1-alfa<<"*C";
                    }
            if (r3==0 &&r6==0)
                if (r1/r4==r2/r5) {
                alfa=r1/r4;
                ok=true;cout<<"Punctele sunt coliniare\n";
                cout<<"B ="<<alfa<<"*A+"<<1-alfa<<"*C";
            }
            if (r1==0 &&r2==0 &&r4==0 &&r5==0) {
                    alfa=r3/r6;ok=true;
                    cout<<"Punctele sunt coliniare\n";
                    cout<<"B ="<<alfa<<"*A+"<<1-alfa<<"*C";
            }
            if (r1==0 &&r3==0 &&r4==0 &&r6==0) {
                    alfa=r2/r5;ok=true;
                    cout<<"Punctele sunt coliniare\n";
                    cout<<"B ="<<alfa<<"*A+"<<1-alfa<<"*C";
            }
             if (r2==0 &&r3==0 &&r5==0 &&r6==0) {
                    alfa=r1/r4;ok=true;
                    cout<<"Punctele sunt coliniare\n";
                    cout<<"B ="<<alfa<<"*A+"<<1-alfa<<"*C";
            }
            if (r1/r4==r2/r5 && r1/r4==r3/r6)   {
                    alfa=r1/r4;ok=true;
                    cout<<"Punctele sunt coliniare\n";
                    cout<<"B ="<<alfa<<"*A+"<<1-alfa<<"*C";
            }

        if (ok==false) cout<<"Punctele nu sunt coliniare\n";
    }
}

int main()
{
    cin>>a.x>>a.y>>a.z>>b.x>>b.y>>b.z>>c.x>>c.y>>c.z;
    colin();
    return 0;
}
