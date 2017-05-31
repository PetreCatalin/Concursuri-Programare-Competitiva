#include <bits/stdc++.h>

using namespace std;

#define PI 3.14159265
#define EPS 0.0000001

struct punct{
    int x,y;
}A,B,C,D;

double dist(punct a,punct b)
{
    return sqrt((a.x-b.x)*(a.x-b.x))+sqrt((a.y-b.y)*(a.y-b.y));
}

int main()
{
     cout<<"Introduceti cele 4 puncte\n";
     cin>>A.x>>A.y>>B.x>>B.y>>C.x>>C.y>>D.x>>D.y;

     double dab,dcd,dad,dbc;
     dab=dist(A,B);
     dcd=dist(C,D);
     dad=dist(A,D);
     dbc=dist(B,C);
     if (dab+dcd==dad+dbc) cout<<"Patrulaterul ABCD este circumscriptibil\n";
     else
        cout<<"Patrulaterul ABCD nu este circumscriptibil\n";

    double abc,adc;
    abc=(A.x-B.x)*(C.x-B.x)+(A.y-B.y)*(C.y-B.y);
    adc=(A.x-D.x)*(C.x-D.x)+(A.y-D.y)*(C.y-D.y);
    abc=(double) abc/(dab*dbc);
    adc=(double) adc/(dad*dcd);

    double rez1=acos(abc) *180.0 / PI;
    double rez2=acos(adc) *180.0 / PI;
    double x=rez1+rez2;

    if (x>=180.0&&x<=180.00001)
        cout<<"Punctul D este pe cerc";
        else
    if (x>180)
        cout<<"Punctul D e in interiorul cercului";
        else
    if (x<180)
        cout<<"Punctul D e in exteriorul cercului";

    return 0;
}
