#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

class AFN{
    int q,q0,nrtr,fin,v,x,y,nr,lungcuvant;
    char l;
    int *F;
    char ***M;
    char *cuv;

    public: void citire(char *nume_fis);
            bool accept();
};

void AFN :: citire(char *nume_fis)
{
    ifstream f(nume_fis);
    f>>q; //nr stari
    f>>v; //card alfabet;
    f>>q0; //starea initiala
    f>>fin; //nr stari finale
    F=new int [fin];
    for (int i=0;i<fin;++i)
        f>>F[i]; //starile finale

    M=new char **[q];
    for (int i=0;i<q;i++) {
        M[i]=new char *[q];
        for (int j=0;j<q;++j)
            M[i][j]=new char [v];
    }

    f>>nrtr; //numar de tranzitii;
    for (int i=1;i<=nrtr;++i) {
        f>>x>>y>>l;
        nr=0;
        while (M[x][y][nr]>='a' &&M[x][y][nr]<='z') ++nr;
        M[x][y][nr]=l;
    }

    f>>lungcuvant; //lungime cuvant
    cuv=new char[lungcuvant];
    f>>cuv; //cuvantul de verificat
};

bool AFN :: accept()
{
    bool ok;
    vector <int> c;
    c.push_back(q0);
    int litera=0,inc,sf,sf1;
    inc=0;sf=0;sf1=0;

    while (litera<=lungcuvant-1) {
        for (int j=inc;j<=sf;++j) {
          int x=c[j];
        for ( int i=0;i<q;++i) {
            nr=0;
            while (M[x][i][nr]>='a' &&M[x][i][nr]<='z') {
                if (M[x][i][nr]==cuv[litera]) {
                    c.push_back(i);
                    sf1++;
                }
                    ++nr;

            }
        }
        }
        inc=sf+1;
        sf=sf1;
        ++litera;
    }

        ok=false;
        for (int i=inc;i<=sf;++i) {
            x=c[i];
        for (int j=0;j<fin;++j)
            if (x==F[j]) {ok=true;break;}
        }

    return ok;
}

int main()
{
    AFN A;
    A.citire("intrare.in");
    if (A.accept()) cout<<"DA";
    else
    cout<<"NU";

    return 0;
}
