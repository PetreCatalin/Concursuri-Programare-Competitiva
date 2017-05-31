#include <fstream>

using namespace std;

long int s1,s2,x,y;
int i,numa[100],numi[100],n,r,aux;

int main()
{
    ifstream f("sumf.in");
    ofstream g("sumf.out");
    f>>n;
    for (i=1;i<=n;i++)
    f>>numa[i]>>numi[i];
    s1=numa[1];
    s2=numi[1];
    for (i=2;i<=n;i++){
           s1=s1*numi[i]+s2*numa[i];
           s2=s2*numi[i];
    }
    r=1;x=s1;y=s2;if (x<y) {aux=x;x=y;y=aux;}
    while (r!=0) {
           r=x%y;
           x=y;
           y=r;
    }
    g<<s1/x<<" "<<"/"<<" "<<s2/x;
    f.close();
    g.close();
    return 0;
}
//a/b+x/y=(a*y+b*x)/b*y - le aducem la acc num. inmultindu-le pe diagonala si inmultind num intre ei .
//nu le aducem neaparat la cel mai mic multiplu comun ..calculam suma tuturor fr. si simplificam doar fractia finala ptr a elimina din timp
