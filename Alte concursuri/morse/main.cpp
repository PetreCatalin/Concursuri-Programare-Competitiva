#include <fstream>
#include <cstring>

using namespace std;

typedef struct {
        char s[20];
        int nr;
} cod;
cod a[5000];
int x,y,i,j,maxim,num,cop;

int main()
{
    ifstream f("morse.in");
    ofstream g("morse.out");
    f>>x>>y;
    maxim=0;
    for (i=x;i<=y;i++) {
        num=0;
        cop=i;
    while (cop>0) {
        if (cop%2==1) {a[i].s[num]='-';a[i].nr++;}
        if (cop%2==0) a[i].s[num]='.';
        cop=cop/2;
        num++;
    }
    if (a[i].nr>maxim) maxim=a[i].nr;
    }

    for (j=x;j<=y;j++)
    if (a[j].nr==maxim)
    {
        for (i=strlen(a[j].s)-1;i>=0;--i)
            g<<a[j].s[i];
        g<<' ';
    }

    f.close();
    g.close();

    return 0;
}

//trecere din baza 10 in b 2 ..se ia numarul se imparte  succesiv la 2 pana devine 0 se noteaza resturile (0 si 1)
//si se formeaza numarul punandule unele langa altele in ordinea inversa in care le-am aflat... ex: 7 -111    11-1011
