#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPS 0.0000001

int x,rep;

struct matrice{
    int n;   //nr linii
    int m;   //nr coloane
    struct complex{
        float re;
        float im;
    }mat[10][10];
}a,b,suma,produs,adjuncta;

void meniu()
{
    printf("---------MENIU----------\n");
    printf("1.Suma a doua matrici\n");
    printf("2.Produsul a doua matrici\n");
    printf("3.Determinantul unei matrici\n");
    printf("4.Inversa unei matrici\n");
    printf("5.Inchiderea meniului\n");
}

void sumamatrici()
{
    int i,j;
    printf("Introduceti numarul de linii al primei matrici:");
    scanf("%d",&a.n);
    printf("Introduceti numarul de coloane al primei matrici:");
    scanf("%d",&a.m);
    printf("Introduceti numarul de linii al celei de-a doua matrici:");
    scanf("%d",&b.n);
    printf("Introduceti numarul de coloane al celei de-a doua matrici:");
    scanf("%d",&b.m);
    printf("\n");

    if (a.n!=b.n ||a.m!=b.m) printf("Cele doua matrici nu se pot aduna\n");

    else {
    printf("Introduceti elementele primei matrici\n");
    for (i=1;i<=a.n;++i)
        for (j=1;j<=a.m;++j) {
            printf("A[%d][%d]:\nPartea reala:",i,j);
            scanf("%f",&a.mat[i][j].re);
            printf(" +i* Partea imaginara:");
            scanf("%f",&a.mat[i][j].im);
        }

    printf("\n");
    printf("Introduceti elementele celei de-a doua matrici\n");
    for (i=1;i<=b.n;++i)
        for (j=1;j<=b.m;++j) {
            printf("B[%d][%d]:\nPartea reala:",i,j);
            scanf("%f",&b.mat[i][j].re);
            printf("+i* Partea imaginara:");
            scanf("%f",&b.mat[i][j].im);
        }

    printf("\nSuma celor doua matrici este:\n");
    for (i=1;i<=a.n;++i)
        for (j=1;j<=a.m;++j) {
            suma.mat[i][j].re=a.mat[i][j].re+b.mat[i][j].re;
            suma.mat[i][j].im=a.mat[i][j].im+b.mat[i][j].im;
        }

    for (i=1;i<=a.n;++i) {
        for (j=1;j<=a.m;++j) {
            printf("%0.2f  ",suma.mat[i][j].re);
            if (suma.mat[i][j].im!=0) printf("+i*%0.2f   ",suma.mat[i][j].im);
            suma.mat[i][j].re=0;
            suma.mat[i][j].im=0;
        }
        printf("\n");
    }
    }
}

double produsreal(double a,double b,double c,double d)
{
    return a*c-b*d;
}

double produsimaginar(double a,double b,double c,double d)    //(a+i*b)(c+i*d)=ac-bd+i*(bc+ad)
{
    return b*c+d*a;
}

void produsmatrici()
{
    int i,j,k;
    printf("Introduceti numarul de linii al primei matrici:");
    scanf("%d",&a.n);
    printf("Introduceti numarul de coloane al primei matrici:");
    scanf("%d",&a.m);
    printf("Introduceti numarul de linii al celei de-a doua matrici:");
    scanf("%d",&b.n);
    printf("Introduceti numarul de coloane al celei de-a doua matrici:");
    scanf("%d",&b.m);
    printf("\n");

    if (a.m!=b.n) printf("Cele doua matrici nu se pot inmulti\n");
    else {
         printf("Introduceti elementele primei matrici\n");
    for (i=1;i<=a.n;++i)
        for (j=1;j<=a.m;++j) {
            printf("A[%d][%d]:\nPartea reala:",i,j);
            scanf("%f",&a.mat[i][j].re);
            printf(" +i* Partea imaginara:");
            scanf("%f",&a.mat[i][j].im);
        }

    printf("\n");
    printf("Introduceti elementele celei de-a doua matrici\n");
    for (i=1;i<=b.n;++i)
        for (j=1;j<=b.m;++j) {
            printf("B[%d][%d]:\nPartea reala:",i,j);
            scanf("%f",&b.mat[i][j].re);
            printf("+i* Partea imaginara:");
            scanf("%f",&b.mat[i][j].im);
        }

    for (i=1;i<=a.n;++i)
        for (j=1;j<=b.m;++j)    //matricea produs va avea dimensiunile a.n,b.m
                for (k=1;k<=b.n;++k) {
                produs.mat[i][j].re+=produsreal(a.mat[i][k].re,a.mat[i][k].im,b.mat[k][j].re,b.mat[k][j].im);
                produs.mat[i][j].im+=produsimaginar(a.mat[i][k].re,a.mat[i][k].im,b.mat[k][j].re,b.mat[k][j].im);
            }

    printf("Produsul celor doua matrici este:\n");
    for (i=1;i<=a.n;++i) {
        for (j=1;j<=b.m;++j) {
            printf("%0.2f    ",produs.mat[i][j].re);
            if (produs.mat[i][j].im!=0) printf("+i*%0.2f    ",produs.mat[i][j].im);
            produs.mat[i][j].re=0;
            produs.mat[i][j].im=0;
        }
        printf("\n");
    }
    }
}

int sol[100];

int semnpermutare(int sol[100],int n)
{
    int nr,i,j;
    nr=0;
    for (i=1;i<n;++i)
        for (j=i+1;j<=n;++j)
            if (sol[i]>sol[j]) ++nr;
    if (nr%2==0) return 1;
    else
    return -1;
}

int ok(int k){
    int i;
    for (i=1;i<k;++i)
        if (sol[k]==sol[i]) return 0;
    return 1;
}

float sre=0,sim=0;

void back(int k,int n)
{
    int i,j;
    float detr=1,detim=0,d1,d2;  //elementul neutru la inmultire 1+i*0
    if (k>n) {
        int semn=semnpermutare(sol,n);
        d1=detr;
        d2=detim;
        for (j=1;j<=n;++j) {
            detr=produsreal(a.mat[j][sol[j]].re,a.mat[j][sol[j]].im,d1,d2);
            detim=produsimaginar(a.mat[j][sol[j]].re,a.mat[j][sol[j]].im,d1,d2);
            d1=detr;
            d2=detim;
        }
        detr=detr*semn;
        detim=detim*semn;
        sre+=detr;
        sim+=detim;
    }
    else
    {
        for (i=1;i<=n;++i) {
            sol[k]=i;
            if (ok(k)==1)
                back(k+1,n);
        }
    }
}

void determinant()
{
    sre=0;
    sim=0;
    int i,j;
    printf("Introduceti numarul de linii:");
    scanf("%d",&a.n);
    printf("Introduceti numarul de coloane:");
    scanf("%d",&a.m);
    if (a.n!=a.m) printf("Matricea nu este patratica,nu putem calcula determinantul\n");
    else {
        printf("\n");
        printf("Introduceti elementele matricei:\n");
        for (i=1;i<=a.n;++i)
        for (j=1;j<=a.m;++j) {
            printf("A[%d][%d]:\nPartea reala:",i,j);
            scanf("%f",&a.mat[i][j].re);
            printf(" +i* Partea imaginara:");
            scanf("%f",&a.mat[i][j].im);
        }

     back(1,a.n);   //facem determinantul matricii folsind formula cu permutari

     printf("\n");
     printf("Determinantul matricii este:\n");
     printf("%0.2f    ",sre);
     if (sim!=0) printf("+i*%0.2f    ",sim);
     printf("\n");
    }
}

void inversa()
{
    float raport;
    sre=0;sim=0;
    float sre1,sim1;
    int i,j,r,t;
    printf("Introduceti numarul de linii:");
    scanf("%d",&a.n);
    printf("Introduceti numarul de coloane:");
    scanf("%d",&a.m);
    if (a.n!=a.m) printf("Matricea nu este patratica,nu putem calcula determinantul\n");
    else {
        printf("\n");
        printf("Introduceti elementele matricei:\n");
        for (i=1;i<=a.n;++i)
        for (j=1;j<=a.m;++j) {
            printf("A[%d][%d]:\nPartea reala:",i,j);
            scanf("%f",&a.mat[i][j].re);
            printf(" +i* Partea imaginara:");
            scanf("%f",&a.mat[i][j].im);
        }

     back(1,a.n);

     printf("\n");
     printf("Determinantul matricii este: ");
     printf("%0.2f    ",sre);
     if (sim!=0) printf("+i*%0.2f    ",sim);
     printf("\n");

    if (fabs(sre)<EPS &&fabs(sim)<EPS)
        printf("Matricea are determinantul 0,nu ii putem calcula inversa\n");
    else {
        for (i=1;i<=a.n;++i)
            for (j=1;j<=a.m;++j)
                b.mat[i][j]=a.mat[j][i];    //calculam transpusa;

        if (fabs(sim)<EPS) {                //daca matricea nu are parte imaginara
            raport=(float) 1/sre;
            printf("1/det A=%0.2f\n",raport);
        }
        else {
            printf("1/det A=1/(%0.2f +i* %0.2f)\n",sre,sim);
            sre1=sre;
            sim1=sim;
        }

        //calculam complementarele
        for (i=1;i<=a.n;++i)
            for (j=1;j<=a.m;++j) {
                    for (r=1;r<i;++r)                //patrat stanga sus
                        for (t=1;t<j;t++)
                            a.mat[r][t]=b.mat[r][t];
                    for (r=1;r<i;++r)                //patrat dreapta sus
                        for (t=j+1;t<=a.m;t++)
                            a.mat[r][t-1]=b.mat[r][t];
                    for (r=i+1;r<=a.n;++r)             //patrat stanga jos
                        for (t=1;t<j;++t)
                            a.mat[r-1][t]=b.mat[r][t];
                    for (r=i+1;r<=a.n;++r)             //patrat dreapta jos
                        for (t=j+1;t<=a.m;++t)
                            a.mat[r-1][t-1]=b.mat[r][t];
            sre=0;sim=0;
            back(1,a.n-1);
            adjuncta.mat[i][j].re=pow(-1,i+j) *sre;
            adjuncta.mat[i][j].im=pow(-1,i+j) *sim;
            }

            printf("\n");
            printf("Inversa matricii este:\n");
            if (fabs(sim)<EPS) {
                for (i=1;i<=a.n;++i) {
                    for (j=1;j<=a.m;++j) {
                    adjuncta.mat[i][j].re=adjuncta.mat[i][j].re*raport;
                    adjuncta.mat[i][j].im=adjuncta.mat[i][j].im*raport;
                    printf("%0.2f     ",adjuncta.mat[i][j].re);
                    if (adjuncta.mat[i][j].im!=0) printf("+i*%0.2f    ",adjuncta.mat[i][j].im);
                    }
                printf("\n");
                }
            }
            else {
                for (i=1;i<=a.n;++i) {
                    for (j=1;j<=a.m;++j)
                    printf("(%0.2f +i* %0.2f)/(%0.2f +i* %0.2f)   ",adjuncta.mat[i][j].re,adjuncta.mat[i][j].im,sre1,sim1);
                printf("\n");
                }
            }
        }
    }
}

int main()
{
    rep=1;
    while (rep==1) {
        printf("\n");
        meniu();
        printf("\nAlegeti optiunea dorita:");
        scanf("%d",&x);
        printf("\n");
        if (x==5) {return 0;rep=0;}
        if (x==1) sumamatrici();
        if (x==2) produsmatrici();
        if (x==3) determinant();
        if (x==4) inversa();
        if (x>5) printf("Optiunea aleasa nu exista\n");
    }

    return 0;
}
