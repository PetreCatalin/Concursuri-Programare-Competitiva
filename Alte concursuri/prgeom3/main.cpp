#include <bits/stdc++.h>

using namespace std;

struct punct{
    int x,y;
    char p;
}A,B,C,D;

punct aux;
double int1,int2,mab,mcd;
double s1x,s1y,s2x,s2y,s,t;
int x1,x2,i,j;

int det(punct A,punct B,punct C)
 {
 return A.x*B.y+ B.x*C.y+C.x*A.y-B.x*A.y-C.x*B.y-C.y*A.x;
 }

int main()
{
    A.p='A';B.p='B';C.p='C';D.p='D';
    cout<<"Introduceti cele 4 puncte\n";
    cin>>A.x>>A.y>>B.x>>B.y>>C.x>>C.y>>D.x>>D.y;
    x1=det(A,B,C);
    x2=det(B,C,D);
    if (x1==0 &&x2==0) {
        cout<<"Punctele sunt coliniare\n";
        punct v[5];
            v[0].x=A.x;v[0].y=A.y;v[0].p=A.p;
            v[1].x=B.x;v[1].y=B.y;v[1].p=B.p;
            v[2].x=C.x;v[2].y=C.y;v[2].p=C.p;
            v[3].x=D.x;v[3].y=D.y;v[3].p=D.p;

    if (A.x==B.x &&A.x==C.x &&A.x==D.x) { //dreapta verticala
        for (i=0;i<=2;++i)
            for (j=i+1;j<=3;++j)
                if (v[i].y>v[j].y) {
                aux=v[i];
                v[i]=v[j];
                v[j]=aux;
            }

    if  ((v[1].p=='A' &&v[0].p=='B') || (v[1].p=='B' &&v[0].p=='A') || (v[1].p=='C' &&v[0].p=='D') || (v[1].p=='D' &&v[0].p=='C'))
        cout<<"Segmentele nu se intersecteaza\n";
    else {
        cout<<"Segmentul de intersectie este:";
        cout<<v[1].p<<v[2].p<<'\n';
    }
    }

    else { //nu e dreapta verticala
        for (i=0;i<=2;++i)
            for (j=i+1;j<=3;++j)
                if (v[i].x>v[j].x) {
                aux=v[i];
                v[i]=v[j];
                v[j]=aux;
            }

    if  ((v[1].p=='A' &&v[0].p=='B') || (v[1].p=='B' &&v[0].p=='A') || (v[1].p=='C' &&v[0].p=='D') || (v[1].p=='D' &&v[0].p=='C'))
        cout<<"Segmentele nu se intersecteaza\n";
    else {
        cout<<"Segmentul de intersectie este:";
        cout<<v[1].p<<v[2].p<<'\n';
    }

    }
    }

    else {
        cout<<"Punctele nu sunt coliniare\n";
        double a1,a2,b1,b2,c1,c2,m1,m2;
        a1=B.y-A.y;
        b1=A.x-B.x;
        c1=a1*A.x+b1*A.y;
        a2=D.y-C.y;
        b2=C.x-D.x;
        c2=a2*C.x+b2*C.y;

        m1=-a1/b1;m2=-a2/b2;
        if (abs(m1-m2)<0.00001) cout<<"Segmentele sunt paralele,nu se intersecteaza\n";
        else {
                double x,y;
                x=(double) (b2*c1-c2*b1)/(a1*b2-a2*b1);
                y=(double) (a1*c2-a2*c1)/(a1*b2-a2*b1);
                int ok=0;
                if (min(A.x,B.x)<=x&&x<=max(A.x,B.x) &&min(A.y,B.y)<=y&&y<=max(A.y,B.y) &&
                    min(C.x,D.x)<=x&&x<=max(C.x,D.x) &&min(C.y,D.y)<=y&&y<=max(C.y,D.y)) ok=1;
                if (ok==0) cout<<"Segmentele nu se intersecteaza\n";
                else
                    cout<<"Punctul de intersectie al celor doua segmente este: "<<x<<' '<<y;
        }
    }

    return 0;
}
