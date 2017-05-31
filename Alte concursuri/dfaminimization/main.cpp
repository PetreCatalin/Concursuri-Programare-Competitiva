#include <fstream>
#include <vector>

using namespace std;

int q,fin,i,q0,nr,x,y,*F,j,**D,*st,v,s1,s2,t,aux,*ech,r,nrf,*finale;
char c,**M,k;
bool ok;
vector <pair <int,int> >per;

int main()
{
    ifstream f("intrare.in");
    ofstream g("iesire.out");
    f>>q; //nr stari
    f>>v; //card alfabet
    f>>fin; //nr stari finale
    F=new int [fin];
    st=new int [q];
    for (i=0;i<fin;++i) {
        f>>F[i];
        st[F[i]]=1;
        } //starile finale
    f>>q0; //starea initiala;
    f>>nr; //nr tranzitii

    M=new char *[q];
    for (i=0;i<q;++i)
        M[i]=new char [q];

    for (i=1;i<=nr;++i) {
            f>>x>>y>>c;
            M[x][y]=c;
    }

    D=new int *[q];
    for (i=0;i<q;++i)
        D[i]=new int [q];

    for (i=1;i<q;++i)
        for (j=0;j<i;++j)
            if ((st[i]==1 &&st[j]!=1) || (st[i]!=1 &&st[j]==1)) D[i][j]=1;
            else {
            per.push_back(make_pair(i,j));
            D[i][j]=0;
            }

   /* for (i=1;i<q;++i) {
        for (j=0;j<i;++j)
            g<<D[i][j]<<" ";
        g<<"\n";
    } */

    ok=true;
    while (ok==true) {
            ok=false;
                   for (r=0;r<per.size();++r) {
                        i=per[r].first;
                        j=per[r].second;

                    for (k='a';k<'a'+v;++k) {
                            for (t=0;t<q;++t)
                                if (M[i][t]==k) {s1=t;break;}
                            for (t=0;t<q;++t)
                                if (M[j][t]==k) {s2=t;break;}
                            if (s1<s2) {
                                    aux=s1;
                                    s1=s2;
                                    s2=aux;
                            }

                            if (D[s1][s2]==1) {
                                    per.erase(per.begin()+r);
                                    --r;
                                    D[i][j]=1;
                                    if (ok==false) ok=true;
                                    break;
                            }
                    }
                   }
    }

   /*  for (i=1;i<q;++i) {
        for (j=0;j<i;++j)
            g<<D[i][j]<<" ";
        g<<"\n";
    } */

    nr=0;
    ech=new int [q];
    for (i=0;i<q;++i)
        ech[i]=0;

    for (i=q-1;i>=0;--i)
        if (ech[i]==0) {
            ++nr;
            ech[i]=nr;
        for (j=0;j<i;++j)
            if (D[i][j]==0) ech[j]=nr;
        }


  /*  for (i=0;i<q;++i)
        g<<ech[i]<<' ';
    g<<"\n"; */

    g<<"Numar de stari: "<<nr<<"\n";
    for (j=1;j<=nr;++j) {
        g<<"Starea "<<j<<": {";
        for (i=0;i<q;++i)
            if (ech[i]==j)
                g<<i<<" ";
        g<<"}\n";
    }

    finale=new int [q];
    for (i=1;i<=q;++i)
        finale[i]=0;
    nrf=0;

    for (i=0;i<=q;++i)
            if (st[i]==1)  //daca starea e finala
               if (finale[ech[i]]==0) {finale[ech[i]]=1;++nrf;}

    g<<"Numarul de stari finale: "<<nrf<<"\n";
    g<<"Starile finale sunt: ";
    for (i=1;i<=nr;++i)
        if (finale[i]==1) g<<i<<' ';
    g<<"\n";

    g<<"Tranzitiile sunt:\n";
    for (i=1;i<=nr;++i)
            for (j=0;j<q;++j)
            if (ech[j]==i) {
                for (r=0;r<q;++r)
                    if (M[j][r]>='a' &&M[j][r]<='a'+v-1)
                        g<<i<<' '<<ech[r]<<' '<<M[j][r]<<"\n";
                break;
            }

    f.close();
    g.close();
    return 0;
}

/*
Ex 1
7 2
2
4 6
0
14
0 1 a
0 5 b
1 2 a
1 3 b
2 2 a
2 3 b
3 4 a
3 6 b
4 2 a
4 3 b
5 4 a
5 6 b
6 6 b
6 4 a

Ex 2
6 2
4
0 2 3 5
0
12
0 0 a
0 1 b
1 2 a
1 4 b
2 2 a
2 3 b
3 3 a
3 5 b
4 2 a
4 4 b
5 3 a
5 2 b
*/
